#include "Parser.h"
#include "../TreeNodes/Negation.h"
#include "../TreeNodes/Multiplication.h"
#include "../TreeNodes/Addition.h"
#include "../TreeNodes/Division.h"
#include "../TreeNodes/Number.h"
#include <math.h>
#include <string>
#include <iostream>

int Parser::findClosingBracket(const std::string &str, const int &index)
{
    int copyOfIndex = index;
    int counter = 0;
    while (copyOfIndex < str.length() - 1)
    {
        if (str[copyOfIndex] == '(')
            ++counter;
        if (str[copyOfIndex] == ')')
        {
            if(counter == 0)
                return copyOfIndex;
            --counter;
        }
        ++copyOfIndex;
    }
}

bool Parser::consume(const std::string &str, int &index, const char &x)
{
    if (index == str.length() - 1)
    {
        return false;
    }
    if (str.at(index) == x)
    {
        index++;
        return true;
    }
    return false;
}
void Parser::skipSpaces(const std::string &str, int &index)
{
    if (str.length() == index + 1)
        return;
    while (consume(str, index, ' '))
        ;
}

TreeNode *Parser::parse(const std::string &str)
{
    int index = 0;
    TreeNode *result = parseF(str, index);
    return result == nullptr ? new Number(0) : result;
}

TreeNode *Parser::parseF(const std::string &str, int &index)
{
    std::cout << "\nparseF()";
    skipSpaces(str, index);
    
}

TreeNode *Parser::parseB(const std::string &str, int &index)
{
    std::cout << "\nparseB()";
    skipSpaces(str, index);
    if (consume(str, index, '('))
    {
        TreeNode *result = parseF(str, index);
        if (!consume(str, index, ')'))
            // throw invalid input exception
            return result;
    }
    if (isDigit(str.at(index)))
    {
        return parseI(str, index);
    }
    // throw invalid input exception
    return nullptr;
}

TreeNode *Parser::parseR(const std::string &str, int &index, TreeNode *leftSide)
{
    std::cout << "\nparseR()";
    if (index == str.length() - 1)
    {
        return leftSide;
    }
    skipSpaces(str, index);
    if (consume(str, index, '+')) // R -> +BR
        return parseR(str, index, new Addition(leftSide, parseB(str, index)));
    if (consume(str, index, '-')) // R -> -BR
        return parseR(str, index, new Addition(leftSide, new Negation(parseB(str, index))));
    if (consume(str, index, '*')) // R -> *BR
        return parseR(str, index, new Multiplication(leftSide, parseB(str, index)));
    if (consume(str, index, '/')) // R -> /BR
        return parseR(str, index, new Division(leftSide, parseB(str, index)));
    // throw invalid input exception
    return nullptr;
}

TreeNode *Parser::parseI(const std::string &str, int &index)
{
    std::cout << "\nparseI()";
    std::string result;
    while (isDigit(str.at(index)))
    {
        result += str.at(index++);
        if (str.length() - 1 == index)
            break;
    }
    // calculate the number
    int number = 0;
    int power = 0;
    int len = result.length();
    int i = len;
    while (i-- > 0)
        number += (result.at(i) - '0') * pow(10, power++);
    return new Number(number);
}

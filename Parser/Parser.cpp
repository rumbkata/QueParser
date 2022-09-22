#include "Parser.h"

static bool Parser::consume(const std::string &str, int &index, const char &x)
{
    if (str.at(index) == x)
    {
        index++;
        return true;
    }
    return false;
}
static void Parser::skipSpaces(const std::string &str, int &index)
{
    while (consume(str, index, ' '))
        ;
}

static Parser::TreeNode *parse(const std::string &str)
{
    int index = 0;
    TreeNode *result = parseF(str, index);
    return result == nullptr ? new Number(0) : result;
}

static TreeNode *Parser::parseF(const std::string &str, int &index)
{
    skipSpaces(str, index);
    if (consume(str, index, '(')) // F -> (F)
    {
        TreeNode *result = parseF(str, index);
        if (!consume(str, index, ')'))
            // throw invalid input exception
            return result;
    }
    if (consume(str, index, '+')) // F -> +F
        return parseF(str, index);
    if (consume(str, index, '-')) // F -> -BR
    {
        TreeNode *parsed = new Negation(parseB(str, index));
        return ParseR(str, index, parsed);
    }
    // default case: F -> BR
    // wrong input will be dealt with in parseB call
    TreeNode *parsed = parseB(str, index);
    return ParseR(str, index, parsed);
}

static TreeNode *Parser::parseB(const std::string &str, int &index)
{
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

static TreeNode *Parser::parseR(const std::string &str, int &index, TreeNode *&leftSide)
{
    skipSpaces(str, index);
    if (consume(str, index, '+')) // R -> +BR
        return parseR(str, index, new Addition(leftSide, parseB(str, index)));
    if (consume(str, index, '-')) // R -> -BR
        return parseR(str, index, new Addition(leftSide, new Negation(parseB(str, index))));
    if (consume(str, index, '*')) // R -> *BR
        return parseR(str, index, new Multiplication(leftSide, parseB(str, index)));
    if (consume(str, index, '/')) // R -> /BR
        return parseR(str, index, new Division(leftSide, parseB(str, index)));
    if (index == str.length())
        return leftSide;
    // throw invalid input exception
    return nullptr;
}

static void Parser::parseI(const std::string &str, int &index)
{
    skipSpaces(str, index);
}

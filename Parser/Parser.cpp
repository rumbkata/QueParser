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
    skipSpaces();
    TreeNode *result = parseF(str, index);
    return result == nullptr ? new Number(0) : result;
}

static TreeNode *Parser::parseF(const std::string &str, int &index)
{

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
    skipSpaces();
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

static void Parser::parseR(const std::string &str, int &index, TreeNode *&leftSide)
{
    skipSpaces();
}

static void Parser::parseI(const std::string &str, int &index)
{
    skipSpaces();
}

#include"Parser.h"

static bool Parser::consume(const std::string& str, int& index,const char& x)
{
    if(str.at(index) == x)
    {
        index++; 
        return true;
    }
    return false;
}
static void Parser::skipSpaces(const std::string& str, int& index)
{
    while(consume(str, index, ' '));
}

static Parser::TreeNode* parse(const std::string& str)
{
    int index = 0;
    skipSpaces();
    TreeNode* result = parseF(str, index);
    return result == nullptr ? new Number(0) : result;
}

static TreeNode* Parser::parseF(const std::string& str, int& index)
{
    
    if(consume(str, index, '('))
    {
        TreeNode* result = parseF(str, index);
        if(!consume(str, index, ')'))
            //throw invalid input exception
        return result;
    }
    if(consume(str, index, '+'))
        return parseF(str, index);
    if(consume(str, index, '-'))
    {
        TreeNode* parsed = new Negation(parseB(str, index));
        //parseR and compose
    }

}

static void Parser::parseB(const std::string& str, int& index)
{

}

static void Parser::parseR(const std::string& str, int& index, TreeNode*& leftSide)
{
    skipSpaces();
    
}

static void Parser::parseI(const std::string& str, int& index)
{

}


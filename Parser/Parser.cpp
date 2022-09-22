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

static Parser::TreeNode* parse(const std::string& str)
{
    int index = 0;
    while(consume(str, index, ' ')); //skip spaces
    TreeNode* result = parseF(str, index);
    return result == nullptr ? new Number(0) : result;
}

static TreeNode* Parser::parseF(const std::string& str, int& index)
{
    while(consume(str, index, ' ')); //skip spaces
    TreeNode* result = nullptr;
    if(consume(str, index, '('))
    {
        result = parseF(str, index);
        if(!consume(str, index, ')'))
            //throw invalid input exception
        return result;
    }
    if(consume(str, index, '+'))
        return parseF(str, index);
    if(consume(str, index, '-'))
    {
        retur
    }

}

static void Parser::parseB(const std::string& str, int& index)
{

}

static void Parser::parseR(const std::string& str, int& index)
{

}

static void Parser::parseI(const std::string& str, int& index)
{

}


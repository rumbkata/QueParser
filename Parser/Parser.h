#pragma once
#include<string>


class Parser
{
public:
    Parser();
    static bool isDigit(const char &x) { return x >= '0' && x <= '9'; }
    static bool consume(const std::string &, int &, const char &);
    static void skipSpaces(const std::string &, int &);
    static TreeNode *parseF(const std::string &, int &);
    static TreeNode *parseB(const std::string &, int &);
    static TreeNode *parseR(const std::string &, int &, TreeNode *);
    static TreeNode *parseI(const std::string &, int &);
    static TreeNode *parse(const std::string &);

private:
};
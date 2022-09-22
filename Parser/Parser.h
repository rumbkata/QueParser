#pragma once
#include<string>
#include "../TreeNodes/*.h"


class Parser
{
public:
    Parser();
    static bool consume(const std::string&, int&, const char&);
    static void skipSpaces(const std::string&, int&);
    static TreeNode* parseF(const std::string&, int&);
    static TreeNode* parseB(const std::string&, int&);
    static TreeNode* parseR(const std::string&, int&, TreeNode*&);
    static void parseI(const std::string&, int&);
    static TreeNode* parse(const std::string&);

private:
    class Negation;
    class Division;
    class Number;
    class Addition;
    class Multiplication;
};
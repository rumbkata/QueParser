#pragma once
#include<string.h>
#include "TreeNode.h"


class Parser
{
    public:
    Parser();
    static void parseF();
    static void parseB();
    static void parseR();
    static void parseI();
    static TreeNode* parse(const string& str);

private:
    class Negation;
    class Division;
    class Number;
    class Addition;
    class Multiplication;
};
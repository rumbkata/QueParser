#include "./Parser/Parser.h"
#include "./TreeNodes/TreeNode.h"
#include<string>
#include <iostream>
using namespace std;

int main()
{
    string input = "5+(2+3)";
    while(input!="end")
    {
        cin>>input;
        TreeNode* result = Parser::parse(input);
        cout<<result->eval();
        cout<<endl;
    }
    return 0;   
}

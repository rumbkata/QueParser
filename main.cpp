#include "./Parser/Parser.h"
#include "./TreeNodes/TreeNode.h"
#include<string>
#include <iostream>
using namespace std;

int main()
{
    string input = "(2 +  3)";
    while(input!="end")
    {
        TreeNode* result = Parser::parse(input);
        cout<<endl<<result->eval();
        cout<<endl;
        cin>>input;
    }
    return 0;   
}

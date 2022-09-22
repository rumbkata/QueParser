#include "Division.h"
// TODO: throw exception
Division::Division(TreeNode*& first, TreeNode*& second)
{
    this->first = first;
    this->second = second;
}
int Division::eval()const
{
    secondValue = second->eval();
    if (secondValue == 0)
    {
        //throw division by zero exception
    }
    return first->eval() / second->eval();
}
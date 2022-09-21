#include "Division.h"
// TODO: throw exception
Division::Division(TreeNode*& term)
{
    this->term = term;
}
int Division::eval()const
{
    secondValue = second->eval();
    if (secondValue == 0)
    {
        //throw exception
    }
    return first->eval() / second->eval();
}
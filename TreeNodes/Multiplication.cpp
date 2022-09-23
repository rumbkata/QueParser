#include "Multiplication.h"
#include "TreeNode.h"

Multiplication::Multiplication(TreeNode* first, TreeNode* second)
{
    this->first = first;
    this->second = second;
}
int Multiplication::eval()const
{
    return first->eval() * second->eval();
}
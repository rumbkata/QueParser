#include "Negation.h"
#include "TreeNode.h"

Negation::Negation(TreeNode* term)
{
    this->term = term;
}
int Negation::eval()const
{
    return -term->eval();
}
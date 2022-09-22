#include "Negation.h"

Negation::Negation(TreeNode* term)
{
    this->term = term;
}
int Negation::eval()const
{
    return -term->eval();
}
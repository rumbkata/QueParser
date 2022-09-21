#include "Addition.h"
Addition::Addition(TreeNode*& first, TreeNode*& second)
{
    this->first = first;
    this->second = second;
}
int Addition::eval()const
{
    return first->eval() + second->eval();
}
#pragma once
#include "TreeNode.h"

class Number: public TreeNode
{
private:
    int value;
    Number();
public:
    Number(const int& value);
    int eval()const override;
};
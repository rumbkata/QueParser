#include "TreeNode.h"
#pragma once

class Number: public TreeNode
{
private:
    int value;
    Number();
public:
    Number(const int& value);
    int eval()const override;
};
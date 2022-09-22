#include "TreeNode.h"
#pragma once


class Addition :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Addition();
public:
    Addition (TreeNode*& first, TreeNode*& second);
    int eval()const override;
};
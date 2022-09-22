#include "TreeNode.h"
#pragma once


class Addition :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Addition();
public:
    Addition (TreeNode*&, TreeNode*&);
    int eval()const override;
};
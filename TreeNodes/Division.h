#include "TreeNode.h"
#pragma once


class Division :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Division();
public:
    Division(TreeNode*& term);
    int eval()const override;
};
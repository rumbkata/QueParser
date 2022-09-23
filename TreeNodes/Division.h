#pragma once
#include "TreeNode.h"


class Division :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Division();
public:
    Division(TreeNode*, TreeNode*);
    int eval()const override;
};
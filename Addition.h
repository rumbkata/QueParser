#include "TreeNode.h"

class Addition :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Addition();
public:
    Addition (TreeNode*& first, Treenode*& second);
    int eval()const override;
};
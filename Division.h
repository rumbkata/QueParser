#include "TreeNode.h"

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
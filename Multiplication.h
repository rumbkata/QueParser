#include "TreeNode.h"

class Multiplication :public TreeNode
{
private:
    TreeNode* first;
    TreeNode* second;
    Multiplication();
public:
    Multiplication (TreeNode*& first, Treenode*& second);
    int eval()const override;
};
#include "TreeNode.h"

class Negation :public TreeNode
{
private:
    TreeNode* term;
    Negation();
public:
    Negation(TreeNode*& term);
    int eval()const override;
};
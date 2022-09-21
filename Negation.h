#include "TreeNode.h"
class Negation :public TreeNode
{
private:
    TreeNode* term;
    Negation();
public:
    Negation(TreeNode* t);
    int eval();
};
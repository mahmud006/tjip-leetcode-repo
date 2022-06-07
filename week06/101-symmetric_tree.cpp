// TC - O(n)
// MC - O(1)
// n = no of nodes
class Solution
{
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;
        if (p->val != q->val)
            return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root->left, root->right);
    }
};
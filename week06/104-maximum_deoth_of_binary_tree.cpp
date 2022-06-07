// TC - O(n)
// MC - O(1)
// n = no of nodes
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return max(L, R) + 1;
    }
};
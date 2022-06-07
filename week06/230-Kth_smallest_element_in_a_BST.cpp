//TC - O(k)
//MC - O(1)

class Solution {
public:
    void runInorder(TreeNode* root, int &k, int &kthValue){
        if(!root) return;
        runInorder(root->left, k, kthValue);
        k--;
        if(k==0){
            kthValue = root->val;
            return;
        }
        runInorder(root->right, k, kthValue);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthValue;
        runInorder(root, k, kthValue);
        return kthValue;
    }
};
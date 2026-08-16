/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int check(TreeNode* node){
        if(node == nullptr) return 0;
        int lSum = max(0, check(node->left));
        int rSum = max(0, check(node->right));

        ans = max(ans, node->val+lSum+rSum);
        return node->val+max(lSum, rSum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        check(root);
        return ans;
    }
};
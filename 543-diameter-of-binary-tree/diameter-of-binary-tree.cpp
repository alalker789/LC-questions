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
    int check(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int lH = check(root->left, maxi);
        int rH = check(root->right, maxi);

        maxi = max(maxi, lH+rH);
        return 1 + max(lH, rH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        check(root, maxi);
        return maxi;
    }
};
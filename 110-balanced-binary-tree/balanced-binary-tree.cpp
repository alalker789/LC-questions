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
    // brute force
    // int heightTree(TreeNode* root){
    //     if(root == NULL) return 0;

    //     return 1 + max(heightTree(root->left), heightTree(root->right)); 
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL) return true;
    //     int lh = heightTree(root->left);
    //     int rh = heightTree(root->right);

    //     if(abs(rh-lh)>1) return false;

    //     bool left = isBalanced(root->left);
    //     bool right = isBalanced(root->right);

    //     if(!left || !right) return false;

    //     return true;
    // }

    //optimised
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        int lH = dfsHeight(root->left);
        if(lH==-1) return -1;
        
        int rH = dfsHeight(root->right);
        if(rH==-1) return -1;

        if(abs(lH-rH)>1) return -1;
        return 1+max(lH, rH);
    }
    
    bool isBalanced(TreeNode* root){
        return dfsHeight(root) != -1;
    }

};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, vector<TreeNode*>& ans, TreeNode* res){
        if(!root) return false;
        ans.push_back(root);

        if(root == res) return true;

        if(getPath(root->left, ans, res) || getPath(root->right, ans, res)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> x;
        vector<TreeNode*> y;

        getPath(root, x, p);
        getPath(root, y, q);

        TreeNode* ans;
        for(int i=0 ; i<min(x.size(), y.size()) ; i++){
            if(x[i] != y[i]) break;
            ans = x[i]; 
        }
        return ans;
    }
};
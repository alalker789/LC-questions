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
    bool getPath(TreeNode* node, TreeNode* req, vector<TreeNode*>& res){
        if(!node) return false;
        res.push_back(node);
        if(req == node) return true;
        if(getPath(node->left, req, res) || getPath(node->right, req, res)) return true;

        res.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> x;
        vector<TreeNode*> y;
        getPath(root, p, x);
        getPath(root, q, y);

        TreeNode* ans = nullptr;
        int n = min(x.size(), y.size());
        for(int i=0 ; i<n ; i++){
            if(x[i] != y[i]) break;
            ans = x[i];
        }
        return ans;
    }
};
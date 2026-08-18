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
    void solve(TreeNode* node, string path, vector<string>& ans){
        if(!node) return;
        if(!node->left && !node->right){
            ans.push_back(path + to_string(node->val));
            return;
        }

        path += to_string(node->val) + "->";
        solve(node->left, path, ans);
        solve(node->right, path, ans);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        solve(root, "", ans);
        return ans;
    }
};
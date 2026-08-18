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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans = 1;
        queue<pair<TreeNode*, int>> q;
        
        q.push({root, 0});

        while(!q.empty()){
            long long start = q.front().second;
            long long end = q.back().second;
            ans = max(ans, end-start+1);
            long long n = q.size();
            for(int i=0 ; i<n ; i++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long idx = p.second;
                if(node->left) q.push({node->left, 2*idx+1});
                if(node->right) q.push({node->right, 2*idx+2});
            }
        }
        return ans;
    }
};
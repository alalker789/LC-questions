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
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWid = 0;

        while(!q.empty()){
            int n = q.size();
            long long mini = q.front().second;
            long long start = 0, end = 0;
            for(int i=0 ; i<n ; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - mini;
                q.pop();
                if(i==0) start = idx;
                if(i==n-1) end = idx;

                if(node->left) q.push({node->left, 2*idx + 1});
                if(node->right) q.push({node->right, 2*idx + 2});
            }
            maxWid = max(maxWid, (int)(end-start+1));
        }
        return maxWid;
    }
};
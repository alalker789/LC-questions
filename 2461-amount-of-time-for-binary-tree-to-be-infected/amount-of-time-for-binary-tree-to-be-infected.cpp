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
    TreeNode* mapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, int start){
        TreeNode* res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;

            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findMinTime(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* trgt){
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(trgt);
        vis[trgt] = true;
        int maxi = 0;

        while(!q.empty()){
            int size = q.size();
            int fl = 0;
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl = 1;
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl = 1;
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(mpp[node] && !vis[mpp[node]]){
                    fl = 1;
                    vis[mpp[node]]=true;
                    q.push(mpp[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* trgt = mapParent(root, mpp, start);

        int maxi = findMinTime(mpp, trgt);
        return maxi;
    }
};
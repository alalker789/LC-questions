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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMark){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parentMark[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMark[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMark;
        markParent(root, parentMark);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        while(!q.empty()){
            int size = q.size();
            if(currLevel++ == k) break;

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parentMark[node] && !visited[parentMark[node]]){
                    visited[parentMark[node]] = true;
                    q.push(parentMark[node]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
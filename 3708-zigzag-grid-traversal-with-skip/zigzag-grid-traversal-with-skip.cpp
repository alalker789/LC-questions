class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        
        bool leftToRight = true;
        int count = 0;   // global traversal counter
        
        for(int i = 0; i < grid.size() ; i++) { 
            if(leftToRight) {
                for(int j = 0; j < grid[i].size(); j++) {
                    if(count % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                    count++;
                }
            } 
            else {
                for(int j = grid[i].size() - 1; j >= 0; j--) {
                    if(count % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                    count++;
                }
            }
            
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
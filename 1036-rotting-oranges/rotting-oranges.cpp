class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];

        int fresh = 0;

        // Step 1: Initialize
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                    vis[i][j] = 0;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Step 2: BFS
        while(!q.empty()){
            auto it = q.front(); q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;

            tm = max(tm, t);

            for(int i=0 ; i<4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                   && vis[nrow][ncol] != 2 
                   && grid[nrow][ncol] == 1){

                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    fresh--;  // orange got rotten
                }
            }
        }

        // Step 3: Check
        if(fresh > 0) return -1;

        return tm;
    }
};
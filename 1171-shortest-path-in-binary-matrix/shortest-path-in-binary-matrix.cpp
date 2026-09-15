class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;
        q.push({1, {0,0}});
        int delrow[] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int delcol[] = {-1,  0,  1, -1, 1,-1, 0, 1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i=0 ; i<8 ; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && 1+dis<dist[nr][nc]){
                    dist[nr][nc] = 1+dis;
                    q.push({1+dis, {nr, nc}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};
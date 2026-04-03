class Solution {
public:
    vector<int>delrow = {-1,0,1,0};
    vector<int>delcol = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({{i,j},0});
            }
        }
        int tm =0;

        while(!q.empty()){
            
                auto it = q.front();
                q.pop();
                int r = it.first.first;
                int c = it.first.second;
                int time = it.second;
                tm = max(tm,time);

                for(int i=0;i<4;i++){
                    int nrow =r+delrow[i];
                    int ncol = c+ delcol[i];

                    if(nrow>=0 && nrow<n &&ncol>=0 &&ncol< m && grid[nrow][ncol]==1){
                        q.push({{nrow,ncol},time+1});
                        grid[nrow][ncol]=2;
                    }
                }
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1)
                return -1;
            }
        }
        return tm;
        
    }
};
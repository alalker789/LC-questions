class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for(int i=0 ; i<4 ; i++){
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='X' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt =0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    cnt++;
                    bfs(i, j, board, vis);
                }
            }
        }
        return cnt;
    }
};
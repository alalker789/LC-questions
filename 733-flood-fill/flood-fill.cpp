class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int newColor, int delrow[], int delcol[], int iniColor){
        int n = image.size();
        int m = image[0].size();

        ans[row][col] = newColor;

        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor ){
                dfs(nrow, ncol, image, ans, newColor, delrow, delcol, iniColor);
            }
        }



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, newColor, delrow, delcol, iniColor);
        return ans;
    }
};
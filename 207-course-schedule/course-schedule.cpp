// this is for directed graph
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& Adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : Adj[node]){
            if(!vis[it]){
                if(dfs(it, Adj, vis, pathVis)==true){
                    return true;
                }
            }
            else if(pathVis[it] == 1){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];

            Adj[b].push_back(a);
        }

        for(int i=0 ; i<numCourses ; i++){
            if(!vis[i]){
                if(dfs(i, Adj, vis, pathVis)==true){
                    return false;
                }
            }
        }
        return true;
    }
};
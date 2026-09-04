class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto e : prerequisites){
            int u = e[0];
            int v = e[1];
            indegree[v]++;
            adjL[u].push_back(v);
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int cntTopo = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cntTopo++;
            
            for(auto it : adjL[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cntTopo == numCourses) return true;
        return false;
    }
};
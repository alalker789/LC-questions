class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto e : prerequisites){
            int u = e[0];
            int v = e[1];
            adjL[v].push_back(u);   //v->u
            indegree[u]++;          // increase indegree of u
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adjL[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size() != numCourses){ return {}; }
        return topo;
    }
};
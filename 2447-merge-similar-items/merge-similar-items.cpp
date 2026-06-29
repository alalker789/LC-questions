class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> temp(1001, 0);

        for(auto x : items1){
            temp[x[0]] += x[1];
        }
        for(auto x : items2){
            temp[x[0]] += x[1];
        }

        vector<vector<int>> ans;
        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i]>0){
                ans.push_back({i, temp[i]});
            }
        }
        return ans;
    }
};
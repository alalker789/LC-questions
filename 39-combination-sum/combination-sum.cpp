class Solution {
public:
    void findCombinationSum(int idx, int target, vector<vector<int>>& ans, vector<int>& ds, vector<int>& candidates){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[idx]<= target){
            ds.push_back(candidates[idx]);
            findCombinationSum(idx, target-candidates[idx], ans, ds, candidates);
            ds.pop_back();
        }

        findCombinationSum(idx+1, target, ans, ds, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0, target, ans, ds, candidates);
        return ans;

    }
};
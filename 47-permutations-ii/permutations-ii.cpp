class Solution {
public:
    void recPermute(int idx, vector<int>& nums, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for(int i=idx ; i<nums.size() ; i++){
            if(used.count(nums[i])) continue; //if element is already present, move on next iteration

            used.insert(nums[i]);

            swap(nums[idx], nums[i]);
            recPermute(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recPermute(0, nums, ans);
        return ans;
    }
};
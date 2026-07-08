class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<int>& freq){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(freq[i]==0){
                freq[i] = 1;
                temp.push_back(nums[i]);
                solve(nums, ans, temp, freq);
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<int> freq(n, 0);

        solve(nums, ans, temp, freq);
        return ans;
    }
};
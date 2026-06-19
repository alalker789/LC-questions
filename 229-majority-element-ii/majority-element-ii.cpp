class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            mpp[nums[i]]++;
        }

        for(auto [it1, it2] : mpp){
            if(it2 > n/3) ans.push_back(it1);
        }
        return ans;
    }
};
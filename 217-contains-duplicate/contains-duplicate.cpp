class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }
        for(auto [it1, it2] : mpp){
            if(it2>=2) return true;
        }
        return false;
    }
};
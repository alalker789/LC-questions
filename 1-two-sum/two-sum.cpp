class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            int ist = nums[i];
            if(mpp.find(target - ist) != mpp.end()){
                return {i, mpp[target-ist]};
            }
            mpp[ist] = i;
        }
        return {-1, -1};
    }
};
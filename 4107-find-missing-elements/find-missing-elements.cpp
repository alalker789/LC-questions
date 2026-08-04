class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int, int> mpp;
        vector<int> ans;
        
        int b = *max_element(nums.begin(), nums.end());
        int a = *min_element(nums.begin(), nums.end());
        
        for(int i=a ; i<=b ; i++){
            mpp[i] = 0;
        }
        for(int i=0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second == 0){
                ans.push_back(it.first);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
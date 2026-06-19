class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]%2 == 0){
                mpp[nums[i]]++;
            }
        }

        int maxFreq = 0;
        int mostFreqEle = -1;
        
        for(auto it : mpp){
            if(it.second > maxFreq || (it.second == maxFreq && it.first < mostFreqEle)){
                maxFreq = it.second;
                mostFreqEle = it.first;
            }
        }
        return mostFreqEle;
    }
};
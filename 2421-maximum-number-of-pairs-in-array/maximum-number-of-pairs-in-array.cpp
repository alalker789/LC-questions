class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums)
            mpp[num]++;
        
        int pair = 0;
        int leftOver = 0;

        for (auto it : mpp) {
            pair += it.second / 2;
            leftOver += it.second % 2;
        }
        return {pair, leftOver};
    }
};
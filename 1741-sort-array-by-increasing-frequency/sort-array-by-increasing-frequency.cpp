class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;   
        return a.second < b.second;     
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums)
            mpp[num]++;
        
        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), cmp);

        int j=0;
        for(auto it : v){
            for(int i=0 ; i<it.second ; i++){
                nums[j] = it.first;
                j++;
            }
        }
        return nums;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for(auto num : nums){
            freq[num]++;
        }

        int i=k;
        while(i<=100){
            if(!freq[i])
                return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};
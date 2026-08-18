class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);
    
        for (int num : nums) {
            freq[num]++;
        }

        if (k == 1) {
            int ans = -1;
            for (int i=0 ; i<51 ; i++) {
                if (freq[i] == 1) {
                    ans = max(ans, i);
                }
            }
            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1)
            return max(nums[0], nums[n - 1]);

        if (freq[nums[0]] > 1 && freq[nums[n - 1]] == 1)
            return nums[n - 1];

        if (freq[nums[n - 1]] > 1 && freq[nums[0]] == 1)
            return nums[0];

        return -1;
    }
};
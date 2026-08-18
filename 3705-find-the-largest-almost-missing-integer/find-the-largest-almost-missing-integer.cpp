class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        if (k == 1) {
            int ans = -1;
            for (auto it : mpp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        if (mpp[nums[0]] == 1 && mpp[nums[n - 1]] == 1)
            return max(nums[0], nums[n - 1]);

        if (mpp[nums[0]] > 1 && mpp[nums[n - 1]] == 1)
            return nums[n - 1];

        if (mpp[nums[n - 1]] > 1 && mpp[nums[0]] == 1)
            return nums[0];

        return -1;
    }
};
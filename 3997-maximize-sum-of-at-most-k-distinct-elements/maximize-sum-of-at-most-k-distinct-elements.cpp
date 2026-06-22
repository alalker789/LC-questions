class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;

        while (!nums.empty() && ans.size() < k) {
            auto max_it = max_element(nums.begin(), nums.end());

            int mx = *max_it;
            ans.push_back(mx);

            nums.erase(remove(nums.begin(), nums.end(), mx), nums.end());
        }

        return ans;
    }
};
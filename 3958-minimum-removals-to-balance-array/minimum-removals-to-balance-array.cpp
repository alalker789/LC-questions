class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j=0;
        int len = 1;
        int maxi = nums[0];
        int mini = nums[0];

        while(j<n){
            mini = nums[i];
            maxi = nums[j];

            while(i<j && maxi > (long long)k*mini){
                i++;
                mini = nums[i];
            }
            len = max(len, j-i+1);
            j++;
        }

        return n-len;
    }
};
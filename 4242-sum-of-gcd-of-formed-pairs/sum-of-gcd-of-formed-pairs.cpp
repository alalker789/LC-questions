class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        vector<int> prefixGcd;
        prefixGcd.push_back(nums[0]);

        for(int i=1 ; i<nums.size() ; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd.push_back(gcd(maxi, nums[i]));
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int i=0, j=prefixGcd.size()-1;

        while(i<j){
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};
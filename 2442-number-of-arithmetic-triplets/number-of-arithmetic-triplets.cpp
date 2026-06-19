class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;
        for(int i=0 ; i<n-2 ; i++){
            for(int j=i+1 ; j<n-1 ; j++){
                for(int k=j+1 ; k<n ; k++){
                    if(abs(nums[i]-nums[j]) == diff && abs(nums[j]-nums[k])==diff) ans++;
                }
            }
        }
        return ans;
    }
};
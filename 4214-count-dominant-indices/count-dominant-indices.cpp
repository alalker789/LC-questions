class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        int n = nums.size()-1;

        for(int num : nums){
            sum += num;
        }
        sum -= nums[0];

        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i] > sum/n){
                cnt++;
            }
            n--;
            sum -= nums[i+1];
        }
        return cnt;
    }
};
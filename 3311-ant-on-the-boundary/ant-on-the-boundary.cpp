class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans= 0;
        int cnt = 0;
        for(int num : nums){
            ans += num;
            if(ans==0) cnt++;
        }
        return cnt;    
    }
};
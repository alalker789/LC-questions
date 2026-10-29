class Solution {
public:
    int solve(int idx, vector<int>& dp){
        if(idx==0 || idx==1) return 1;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = solve(idx-1, dp)+solve(idx-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
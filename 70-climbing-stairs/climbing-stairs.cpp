class Solution {
public:
    int solve(int idx, vector<int>& dp){
        if(idx==0) return 1;
        if(idx==1) return 1;

        if(dp[idx] != -1) return dp[idx];

        int first = solve(idx-1, dp);
        int second = solve(idx-2, dp);

        return dp[idx] = first+second;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
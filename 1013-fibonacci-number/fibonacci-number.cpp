class Solution {
public:
    int solve(int idx, vector<int>& dp){
        if(idx<=1) return idx;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = solve(idx-1, dp)+solve(idx-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
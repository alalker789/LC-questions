class Solution {
public:
    int solve(int idx){
        if(idx<=1) return idx;
        return solve(idx-1)+solve(idx-2);
    }
    int fib(int n) {
        return solve(n);
    }
};
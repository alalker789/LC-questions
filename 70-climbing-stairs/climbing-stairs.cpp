class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int s0 = 1, s1 = 1;
        for(int i=2 ; i<=n ; i++){
            int temp = s0+s1;
            s0 = s1;
            s1 = temp;
        }
        return s1;
    }
};
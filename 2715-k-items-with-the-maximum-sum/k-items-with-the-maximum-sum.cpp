class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k<=numOnes) return k;  //  0 < k <= n(1)
        else if(k<=numOnes + numZeros) return numOnes; // 0 < k <= n(1)+n(0) se
        return numOnes - (k - numOnes - numZeros); // n(1)+n(0) < k <= n(1)+n(-1)+n(0)
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int prod = 1;
        int sum = 0;

        while(x>0){
            int last = x%10;
            sum += last;
            prod *= last;
            x /= 10;
        }
        return (n % (sum + prod) == 0);
    }
};
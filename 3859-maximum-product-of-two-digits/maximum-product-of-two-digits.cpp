class Solution {
public:
    int maxProduct(int n) {
        int n1 = 0;
        int n2 = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit >= n1) {
                n2 = n1;
                n1 = digit;
            }
            else if (digit > n2) {
                n2 = digit;
            }

            n /= 10;
        }

        return n1 * n2;
    }
};
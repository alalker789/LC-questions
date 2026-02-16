class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        
        for(int i = 0; i < 32; i++){
            result <<= 1;        // make space for next bit
            result |= (n & 1);   // take last bit of n
            n >>= 1;             // shift n to process next bit
        }
        
        return result;
    }
};
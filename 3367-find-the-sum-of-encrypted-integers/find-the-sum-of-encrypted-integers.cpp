class Solution {
public:
    int encrypt(int x){
        int len = 0;
        int n = x;
        int num = 0;
        int maxi = 0;

        while(n>0){
            len++;
            maxi = max(maxi, n%10);
            n = n/10;
        }

        n = x;
        while(n>0){
            num = num*10 + maxi;
            n = n/10;
        }
        return num;

    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            nums[i] = encrypt(nums[i]);
            sum += nums[i];
        }
        return sum;
    }
};
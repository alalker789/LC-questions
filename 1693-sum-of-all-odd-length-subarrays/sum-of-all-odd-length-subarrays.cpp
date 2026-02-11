class Solution {
public:
    int sumArr(vector<int>& arr, int start, int end){
        int sum = 0;
        for(int i=start ; i<=end ; i++){
            sum += arr[i];
        }
        return sum;
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                if((j-i+1)%2 != 0){
                    totalSum += sumArr(arr, i , j);
                }
            }
        }
        return totalSum;
    }
};
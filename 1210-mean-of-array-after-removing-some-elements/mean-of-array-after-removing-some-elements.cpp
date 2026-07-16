class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int x = (int)n*0.05;
        long long sum = 0;
        for(int i=x ; i<n-x ; i++){
            sum += arr[i];
        }
        return (double)sum/(n-2*x);
    }
};
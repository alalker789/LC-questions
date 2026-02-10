class Solution {
public:
    // bool checkBalananced(vector<int>& nums, int i, int j){
    //     int ecnt = 0, ocnt = 0;
    //     for(int start = i; start<=j ; start++){
    //         if(nums[start]%2==0) ecnt++;
    //         if(nums[start]%2!=0) ocnt++;
    //     }
    //     if(ecnt == ocnt) return true;
    //     return false;
    // }
    // int longestBalanced(vector<int>& nums) {
    //     int maxL = 0;
    //     for(int i=0 ; i<nums.size() ; i++){
    //         for(int j=0 ; j<nums.size() ; j++){
    //             if(checkBalananced(nums, i, j))
    //                 maxL = max(maxL, j-i+1);   
    //         }
    //     }
    //     return maxL;
    // }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        for(int i=0 ; i<n ; i++){
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;
            for(int j=i ; j<n ; j++){
                if(nums[j]%2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if(evenSet.size() == oddSet.size())
                    maxL = max(maxL, j-i+1);
            }
        }
        return maxL;
    }
};
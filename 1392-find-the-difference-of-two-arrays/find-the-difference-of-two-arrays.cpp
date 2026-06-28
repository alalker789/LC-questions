class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> distinctArr1, distinctArr2;

        for(auto st : st1){
            if(st2.count(st) == 0){
                distinctArr1.push_back(st);
            }
        } 
        
        for(auto st : st2){
            if(st1.count(st) == 0){
                distinctArr2.push_back(st);
            }
        } 

        return {distinctArr1, distinctArr2};
    }
};
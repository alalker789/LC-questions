class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> container(nums.begin(), nums.end());

        int multiple = k;
        while(container.count(multiple)){
            multiple += k;
        }
        return multiple;
    }
};
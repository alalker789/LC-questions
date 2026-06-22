class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<float> st;
        sort(nums.begin(), nums.end());
        int i = 0, j=nums.size()-1;

        while(i<=j){
            float avg = (float)(nums[i]+nums[j])/2;
            st.insert(avg);
            i++;
            j--;
        }
        return st.size();
    }
};
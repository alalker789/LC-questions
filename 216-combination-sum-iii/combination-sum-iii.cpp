class Solution {
public:
    void solve(int idx, vector<int>& num, int k, int n, vector<int>& temp, vector<vector<int>>& ans){
        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }

        for(int i=idx ; i<num.size(); i++){
            if(num[i]>n) break;
            temp.push_back(num[i]);
            solve(i+1, num, k-1, n-num[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, num, k, n, temp, ans);
        return ans;
    }
};
class Solution {
public:
    void solve(int idx, string s, vector<string>& ans){
        //due to idx+2 jump we may jump outside the string thatswhy idx>=s.size()
        if(idx >= s.size()){
            ans.push_back(s);
            return;
        }

        //case1: keep the current position as '0' and move next
        solve(idx+1, s, ans);

        s[idx] = '0';
        solve(idx+2, s, ans);

        s[idx] = '1'; 


    }
    vector<string> validStrings(int n) {
        string s(n, '1');
        vector<string> ans;
        solve(0, s, ans);
        return ans;
    }
};
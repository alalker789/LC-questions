class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0 ; i<s.size() ; i++){
            int num = 26 - (int)(s[i]-'a');
            ans += num*(i+1);
        }
        return ans;
    }
};
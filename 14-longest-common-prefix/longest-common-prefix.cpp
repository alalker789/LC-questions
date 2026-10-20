class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        int n1 = strs[0].size();
        int n2 = strs[n-1].size();
        int cnt = 0;

        for(int i=0 ; i<min(n1, n2) ; i++){
            if(strs[0][i] == strs[n-1][i]) cnt++;
            else break;
        }
        return strs[0].substr(0, cnt);
    }
};
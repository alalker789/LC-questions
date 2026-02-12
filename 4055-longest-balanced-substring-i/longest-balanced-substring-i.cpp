class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0 ; i<n ; ++i){
            int freqArr[26] = {};
            int maxFreq = 0, distincts = 0;
            for(int j = i ; j<n ; ++j){
                int idx = s[j] - 'a';
                distincts += (freqArr[idx] == 0);
                maxFreq = max(maxFreq, ++freqArr[idx]);

                if(j-i+1 == distincts*maxFreq)
                    ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(string s){
        int l = s.size();
        if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u') && (s[l-1]=='a'||s[l-1]=='e'||s[l-1]=='i'||s[l-1]=='o'||s[l-1]=='u')) 
            return 1;
        return 0;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;

        for(int i = left ; i<=right ; i++){
            ans += solve(words[i]);
        }
        return ans;
    }
};
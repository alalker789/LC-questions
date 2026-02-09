class Solution {
public:
    bool check(string str, string s){
        if(str.size()>s.size()) return false;

        if(str == s) return true;

        for(int i=0 ; i<str.size() ; i++){
            if(str[i] != s[i])
                return false;
        }
        return true;
    }

    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int cnt = 0;

        for(string str : words){
            if(check(str, s)){
                cnt++;
            }
        }

        return cnt;
    }
};
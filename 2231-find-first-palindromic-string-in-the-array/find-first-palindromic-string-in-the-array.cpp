class Solution {
public:
    bool solve(string s){
        int i=0, j=s.size()-1;

        while(i<j){
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {

        for(string str : words){
            if(solve(str)) return str;
        }
        return "";
    }
};
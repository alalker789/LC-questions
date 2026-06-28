class Solution {
public:
    bool isAlp(char ch){
        ch = tolower(ch);
        return ch>='a' && ch<='z';
    }
    string reverseOnlyLetters(string s) {
        int i=0, j=s.size()-1;

        while(i<=j){
            if(isAlp(s[i]) && isAlp(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!isAlp(s[i])) i++;
            else if(!isAlp(s[j])) j--;
        }
        return s;
    }
};
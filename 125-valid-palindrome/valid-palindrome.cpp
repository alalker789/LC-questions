class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(char ch : s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
                s1.push_back(ch);
            }
        }

        int i = 0, j = s1.length()-1;
        
        while(i<j){
            if(tolower(s1[i]) != tolower(s1[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
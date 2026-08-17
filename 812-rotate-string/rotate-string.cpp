class Solution {
public:
    string rotate(string s){
        char ch = s[0];
        for(int i=1 ; i<s.length() ; i++){
            s[i-1] = s[i];
        }
        s[s.length()-1] = ch;
        return s;
    }
    bool rotateString(string s, string goal) {
        int n = s.length();
        
        for(int i=0 ; i<n ; i++){
            s = rotate(s);
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
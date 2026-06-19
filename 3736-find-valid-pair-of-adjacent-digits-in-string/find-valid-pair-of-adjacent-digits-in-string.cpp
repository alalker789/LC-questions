class Solution {
public:
    string findValidPair(string s) {
        int arr[10] = {0};
        for(char ch : s){
            arr[ch-'0']++;
        }

        for(int i=0 ; i<s.size()-1 ; i++){
            if(s[i]!=s[i+1] && arr[s[i]-'0']==(s[i]-'0') && arr[s[i+1]-'0']==(s[i+1]-'0')){
                return string() + s[i] + s[i+1];
            }
        }
        return "";
    }
};
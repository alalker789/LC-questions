class Solution {
public:
    string removeTrailingZeros(string num) {
        int idx = num.size()-1;
        for(int i=num.size()-1 ; i>=0 ; i--){
            if(num[i] != '0'){
                idx = i;
                break;
            }
        }
        string ans;
        for(int i=0 ; i<=idx ; i++){
            ans.push_back(num[i]);
        }
        return ans;
    }
};
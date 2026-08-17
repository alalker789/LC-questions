class Solution {
public:
    string removeTrailingZeros(string num) {
        int j=-1;
        for(int i=num.size()-1;i>=0;i--){
            if(num[i]!='0'){
                j=i;
                break;
            }
        }
        if(j!=-1){
            return num.substr(0,j-0+1);
        }
        return num;
    }
};
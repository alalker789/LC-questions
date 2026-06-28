class Solution {
public:
    bool isAlph(char ch){
        ch = tolower(ch);
        return ch >= 'a' && ch <= 'z';
    }

    void solveAlp(string &s, int left, int right){
        while(left < right){
            if(isAlph(s[left]) && isAlph(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(!isAlph(s[left])) left++;
            else right--;
        }
    }

    void solveNAlp(string &s, int left, int right){
        while(left < right){
            if(!isAlph(s[left]) && !isAlph(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(isAlph(s[left])) left++;
            else right--;
        }
    }

    string reverseByType(string s) {
        solveAlp(s, 0, s.size() - 1);
        solveNAlp(s, 0, s.size() - 1);
        return s;
    }
};
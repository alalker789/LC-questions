class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        stack<char> st;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                st.push('(');
                cnt = max(cnt, (int)st.size());
            }
            else if(s[i] == ')'){
                st.pop();
            }
        }
        return cnt;
    }
};
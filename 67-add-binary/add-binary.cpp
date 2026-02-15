class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;

        for(int i=0; i<max(a.size(), b.size()) ; i++){
            int A = i<a.size() ? a[i]-'0' : 0;
            int B = i<b.size() ? b[i]-'0' : 0;

            int total = A+B+carry;
            ans.push_back((total%2) + '0');
            carry = total/2;
        }

        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
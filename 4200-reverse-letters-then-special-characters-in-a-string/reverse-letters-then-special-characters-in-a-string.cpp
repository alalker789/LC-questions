class Solution {
public:
    bool isAlp(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    string reverseByType(string s) {
        int i = 0, j = s.size() - 1;

        // Reverse letters
        while (i < j) {
            if (isAlp(s[i]) && isAlp(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!isAlp(s[i]) && !isAlp(s[j])) {
                i++;
                j--;
            }
            else if (!isAlp(s[i])) {
                i++;
            }
            else {
                j--;
            }
        }

        i = 0;
        j = s.size() - 1;

        // Reverse special characters
        while (i < j) {
            if (!isAlp(s[i]) && !isAlp(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (isAlp(s[i]) && isAlp(s[j])) {
                i++;
                j--;
            }
            else if (isAlp(s[i])) {
                i++;
            }
            else {
                j--;
            }
        }

        return s;
    }
};
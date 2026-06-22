class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;

        for(char ch : text) {
            cnt[ch]++;
        }

        return min({
            cnt['b'],
            cnt['a'],
            cnt['l'] / 2,
            cnt['o'] / 2,
            cnt['n']
        });
    }
};
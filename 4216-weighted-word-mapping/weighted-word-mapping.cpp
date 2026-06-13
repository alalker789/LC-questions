class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(int i=0 ; i<words.size() ; i++){
            int cnt = 0;
            
            for(int j=0 ; j<words[i].size() ; j++){
                char ch = words[i][j];
                cnt += weights[ch - 'a'];
            }
            int rem = cnt%26;
            char newChar = 'z' - rem;
            ans.push_back(newChar);
        }
        return ans;
    }
};
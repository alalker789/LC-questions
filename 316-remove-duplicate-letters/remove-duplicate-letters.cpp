class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        
        vector<int> engLetter(26, 0);
        vector<bool> visited(26, false);

        for(char ch : s){
            engLetter[ch - 'a']++;
        }

        for(char ch : s){
            int idx = ch - 'a';
            engLetter[idx]--;

            //skipped if already added!
            if(visited[idx]) continue;

            //for lexicographical order
            while(!ans.empty() && ch < ans.back() && engLetter[ans.back()-'a']>0){
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }


            ans.push_back(ch);
            visited[idx] = true;
        }

        return ans;
    }
};
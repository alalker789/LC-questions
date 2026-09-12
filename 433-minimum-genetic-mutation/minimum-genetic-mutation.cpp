class Solution {
public:
    char arr[4] = {'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        unordered_set<string> st(bank.begin(), bank.end());
        st.erase(startGene);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endGene) return steps;

            for(int i=0 ; i<word.size() ; i++){
                char original = word[i];
                for(int j=0 ; j<4 ; j++){
                    word[i] = arr[j];
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};
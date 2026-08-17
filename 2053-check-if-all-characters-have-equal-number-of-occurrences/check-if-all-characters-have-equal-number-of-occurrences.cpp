class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;

        for(int i=0 ; i<s.size() ; i++){
            mpp[s[i]]++;
        }
        int check = mpp.begin()->second;
        for(auto it : mpp){
            if(it.second != check) return false;
        }
        return true;
    }
};
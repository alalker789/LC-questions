class Solution {
public:
    int countPoints(string rings) {
        map<int, set<char>> mpp;

        for(int i=0 ; i<rings.size() ; i+=2){
            char ch = rings[i];
            
            int num = rings[i+1]-'0';
            mpp[num].insert(ch);
        }
        int cnt=0;
        for(auto it : mpp){
            if(it.second.size() == 3) cnt++;
        }
        return cnt;
    }
};
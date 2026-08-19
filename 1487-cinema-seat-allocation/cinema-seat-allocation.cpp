class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mpp;
        for(auto seat : reservedSeats){
            mpp[seat[0]].insert(seat[1]);
        }
        int ans = (n-mpp.size())*2; // take care if any row is already empty

        for(auto it : mpp){
            auto s = it.second;
            bool left = true;  // 2,3,4,5
            bool mid = true;   // 4,5,6,7
            bool right = true; //6,7,8,9

            for(int seat : s){
                if(seat>=2 && seat<=5) left = false;
                if(seat>=4 && seat<=7) mid = false;
                if(seat>=6 && seat<=9) right = false;
            }
            if(left && right) ans += 2;
            else if(left || mid || right) ans += 1;
        }
        return ans;
    }
};
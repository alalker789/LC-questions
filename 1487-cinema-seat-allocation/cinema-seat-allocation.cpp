class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> mpp;
        for(auto seats : reservedSeats){
            mpp[seats[0]].insert(seats[1]);
        }
        int ans = (n-mpp.size())*2;

        for(auto it : mpp){
            auto s = it.second;
            bool left = true;  //2,3,4,5
            bool mid = true;   //4,5,6,7
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
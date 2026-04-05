class Solution {
public:
    bool judgeCircle(string moves) {
        
        if(moves == "") return true;

        int v=0, h=0;
        for(char ch : moves){
            if(ch == 'U') v++;
            else if(ch == 'D') v--;
            else if(ch == 'R') h++;
            else if(ch == 'L') h--;
        }

        if(v==0 && h==0) return true;
        return false;
    }
};
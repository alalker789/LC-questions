class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int ans = 0;
        int money = coins;

        for(int i=0 ; i<n ; i++){
            if(costs[i]<=money){
                ans++;
                money -= costs[i];
            }
            else break;
        }
        return ans;
    }
};
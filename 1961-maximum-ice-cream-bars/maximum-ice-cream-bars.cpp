class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxPrice = *max_element(costs.begin() , costs.end());
        vector<int> iceCream(maxPrice+1, 0);
        int money = coins;
        for(int price : costs){
            iceCream[price]++;
        }
        int ans = 0;
        for(int price=1 ; price<=maxPrice ; price++){
            //exhaust small price icecream first
            while(iceCream[price]>0 && money>=price){
                ans++;
                money -= price;
                iceCream[price]--;
            }
        }
        return ans;
    }
};
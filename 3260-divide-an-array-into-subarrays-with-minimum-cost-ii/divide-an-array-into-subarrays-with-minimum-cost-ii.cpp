class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 1;
        
        multiset<long long> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;
        
        int left = 1;
        
        for (int right = 1; right < n; right++) {
            
            // Insert nums[right]
            small.insert(nums[right]);
            sumSmall += nums[right];
            
            if ((int)small.size() > need) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
            
            // Maintain window size
            if (right - left + 1 > dist + 1) {
                long long val = nums[left++];
                
                auto itSmall = small.find(val);
                if (itSmall != small.end()) {
                    sumSmall -= val;
                    small.erase(itSmall);
                    
                    if (!large.empty()) {
                        auto itLarge = large.begin();
                        sumSmall += *itLarge;
                        small.insert(*itLarge);
                        large.erase(itLarge);
                    }
                } else {
                    large.erase(large.find(val));
                }
            }
            
            if (right - left + 1 == dist + 1 && 
                (int)small.size() == need) {
                ans = min(ans, sumSmall);
            }
        }
        
        return ans + nums[0];
    }
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        
        // Create events
        for (auto &b : buildings) {
            int L = b[0], R = b[1], H = b[2];
            events.push_back({L, -H}); // building start
            events.push_back({R, H});  // building end
        }
        
        // Sort events
        sort(events.begin(), events.end());
        
        multiset<int> heights;
        heights.insert(0);
        
        int prevMax = 0;
        vector<vector<int>> result;
        
        for (auto &e : events) {
            int x = e.first;
            int h = e.second;
            
            if (h < 0) {
                heights.insert(-h);  // start
            } else {
                heights.erase(heights.find(h)); // end
            }
            
            int currMax = *heights.rbegin();
            
            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }
        
        return result;
    }
};
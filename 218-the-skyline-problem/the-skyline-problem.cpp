class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            // Create events: (x, height) negative height = start, positive = end
    vector<pair<int,int>> events;
    for (auto& b : buildings) {
        events.push_back({b[0], -b[2]}); // start
        events.push_back({b[1],  b[2]}); // end
    }
    
    // Sort by x; at same x, starts before ends (negative before positive)
    sort(events.begin(), events.end());
    
    vector<vector<int>> result;
    // max-heap via map: height -> count (sorted descending)
    map<int, int, greater<int>> active;
    active[0] = 1; // ground level
    
    int prev_max = 0;
    
    for (auto& [x, h] : events) {
        if (h < 0) {
            // Building starts
            active[-h]++;
        } else {
            // Building ends
            if (--active[h] == 0)
                active.erase(h);
        }
        
        int cur_max = active.begin()->first;
        if (cur_max != prev_max) {
            result.push_back({x, cur_max});
            prev_max = cur_max;
        }
    }
    
    return result;
    }
};
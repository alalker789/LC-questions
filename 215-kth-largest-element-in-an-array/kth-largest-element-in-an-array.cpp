class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int x = 1;
        while(x!=k){
            pq.pop();
            x++;
        }
        return pq.top();
    }
};
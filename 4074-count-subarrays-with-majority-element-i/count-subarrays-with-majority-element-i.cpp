

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> xyz = nums;
        int n = nums.size();
        vector<int> arr(n);

        for(int i=0 ; i<n ; i++)
            arr[i] = (nums[i] == target)? 1:-1;

        vector<long long> prefix(n+1,0);
        for(int i=0 ; i<n ; i++){
            prefix[i+1] = prefix[i]+arr[i];
        }

        long long cnt = 0;
        multiset<long long> seen;
        for(int i=0 ; i<=n ; i++){
            cnt += distance(seen.begin(), seen.lower_bound(prefix[i]));
            seen.insert(prefix[i]);
        }
        return (int)cnt;
    }
};
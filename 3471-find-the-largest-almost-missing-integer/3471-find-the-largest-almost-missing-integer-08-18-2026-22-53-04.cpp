class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Case 1: k equals 1
        if (k == 1) {
            int ans = -1;
            for (auto& [num, freq] : counts) {
                if (freq == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }

        // Case 2: k equals the entire array size
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;
        if (counts[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
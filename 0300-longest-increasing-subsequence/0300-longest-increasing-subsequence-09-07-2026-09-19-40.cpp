class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] stores results for current index i and (previous index + 1) j
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }

    int solve(int i, int prev_idx, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;

        // Check if already calculated (offset prev_idx by +1 because indices start at -1)
        if (dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];

        // Choice 1: Skip the current element
        int skip = solve(i + 1, prev_idx, nums, dp);

        // Choice 2: Take the current element (if it's valid)
        int take = 0;
        if (prev_idx == -1 || nums[i] > nums[prev_idx]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        // Store and return the best choice
        return dp[i][prev_idx + 1] = max(skip, take);
    }
};

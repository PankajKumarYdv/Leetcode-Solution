class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // dp[i] stores the maximum number of non-overlapping palindromes in the prefix s[0...i-1]
        vector<int> dp(n + 1, 0);
        
        // g[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> g(n, vector<bool>(n, false));
        
        // Step 1: Precompute all palindromes using standard gap/length DP
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2 || g[i + 1][j - 1]) {
                        g[i][j] = true;
                    }
                }
            }
        }
        
        // Step 2: Linear DP to find the maximum number of non-overlapping intervals
        for (int i = 1; i <= n; ++i) {
            // Option 1: Do not include character s[i-1] into a new valid palindrome
            dp[i] = dp[i - 1];
            
            // Option 2: Check all possible valid palindrome endings at index i-1
            // The length must be at least k, so the starting index `j` can go from 0 up to `i - k`
            for (int j = 0; j <= i - k; ++j) {
                if (g[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};

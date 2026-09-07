class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        // dp[i] stores the number of distinct subsequences ending with the i-th character ('a' to 'z')
        std::vector<long long> dp(26, 0);
        
        // Tracks the total number of distinct non-empty subsequences found so far
        long long total_subsequences = 0;
        
        for (char c : s) {
            int char_idx = c - 'a';
            
            // Subsequences that can be formed ending with the current character:
            // 1 (the single character itself) + all existing distinct subsequences
            long long new_endings = (total_subsequences + 1) % MOD;
            
            // Calculate what this character is adding to the overall count.
            // We add MOD before the modulo operation to safely handle negative values from subtraction.
            long long added_subsequences = (new_endings - dp[char_idx] + MOD) % MOD;
            
            // Update the count for this specific character
            dp[char_idx] = new_endings;
            
            // Update the global running total
            total_subsequences = (total_subsequences + added_subsequences) % MOD;
        }
        
        return total_subsequences;
    }
};
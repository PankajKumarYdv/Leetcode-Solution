class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        
        // Every number from 1,000 onwards introduces at least 1 comma.
        // Every number from 1,000,000 onwards introduces a 2nd comma, and so on.
        for (long long multiplier = 1000; multiplier <= n; multiplier *= 1000) {
            total_commas += (n - multiplier + 1);
        }
        
        return total_commas;
    }
};

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Binary search space for the answer
        long long low = 1;
        // Upper bound: picking the smallest coin k times
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countAmounts(mid, coins, n) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;  // Increase the search range
            }
        }
        return ans;
    }

private:
    long long countAmounts(long long target, vector<int>& coins, int n) {
        long long count = 0;
        int totalSubsets = (1 << n) - 1;

        // Iterate through all non-empty subsets (Inclusion-Exclusion Principle)
        for (int mask = 1; mask <= totalSubsets; mask++) {
            long long currentLcm = 1;
            int setBits = 0;
            bool overflow = false;

            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    setBits++;
                    // Prevent overflow when calculating LCM
                    long long nextLcm = std::lcm(currentLcm, (long long)coins[j]);
                    if (nextLcm > target) { 
                        overflow = true;
                        break;
                    }
                    currentLcm = nextLcm;
                }
            }

            if (overflow) continue;

            // Inclusion-Exclusion formula adjustment
            if (setBits % 2 == 1) {
                count += target / currentLcm;
            } else {
                count -= target / currentLcm;
            }
        }
        return count;
    }
};

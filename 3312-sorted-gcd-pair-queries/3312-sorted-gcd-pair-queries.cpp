class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // Step 1: Precompute the Möbius function using a linear sieve
        vector<int> mu(max_val + 1, 0);
        vector<int> primes;
        vector<bool> is_prime(max_val + 1, true);
        
        mu[1] = 1;
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i <= max_val; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                mu[i] = -1; // Primes have exactly 1 prime factor
            }
            for (int p : primes) {
                if (i * p > max_val) break;
                is_prime[i * p] = false;
                if (i % p == 0) {
                    mu[i * p] = 0; // Contains a squared prime factor
                    break;
                } else {
                    mu[i * p] = -mu[i]; // Multiply by -1 for an additional distinct prime
                }
            }
        }

        // Count frequencies of each number in nums
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        // Step 2: Calculate F[x] - Total pairs where both elements are multiples of x
        vector<long long> F(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            F[i] = multiples * (multiples - 1) / 2;
        }

        // Step 3: Calculate G[x] - Exact pairs with GCD == x using Möbius Inversion
        vector<long long> exact_gcd(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int k = 1; k * i <= max_val; ++k) {
                // Formula: G(x) = sum(mu(k) * F(k * x))
                exact_gcd[i] += mu[k] * F[k * i];
            }
        }

        // Step 4: Build prefix sums for binary search
        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix[i] = prefix[i - 1] + exact_gcd[i];
        }

        // Step 5: Answer each query using binary search
        vector<int> result;
        result.reserve(queries.size());
        
        for (long long q : queries) {
            int left = 1, right = max_val;
            int ans = max_val;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] > q) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            result.push_back(ans);
        }
        
        return result;
    }
};
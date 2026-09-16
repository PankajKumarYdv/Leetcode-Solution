class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function to calculate modular inverse using Fermat's Little Theorem
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function to calculate Modular Inverse
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    // Function to compute nCr % MOD
    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;

        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = (num * (n - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }

public:
    int numberOfSets(int n, int k) {
        // The problem is mathematically equivalent to choosing 2k points out of (n + k - 1) slots.
        // Therefore, the total combinations equal: (n + k - 1) C (2k)
        return nCr(n + k - 1, 2 * k);
    }
};

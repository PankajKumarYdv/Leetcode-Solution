class Solution {
public:
    static const int MOD = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = (int)s.size();

        vector<int> nonZeroCount(n, 0);
        vector<int> numberUpTo(n, 0);
        vector<int> digitSumUpTo(n, 0);
        vector<int> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (int)((1LL * pow10[i - 1] * 10) % MOD);
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        numberUpTo[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; ++i) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; ++i) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numberUpTo[i] = (int)((1LL * numberUpTo[i - 1] * 10 + digit) % MOD);
            } else {
                numberUpTo[i] = numberUpTo[i - 1];
            }
        }

        for (int i = 1; i < n; ++i) {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = (int)queries.size();
        vector<int> result(q, 0);

        for (int i = 0; i < q; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            int numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0) {
                result[i] = 0;
                continue;
            }

            int x = (numberUpTo[r] - (int)((1LL * numBefore * pow10[subStrLen]) % MOD) + MOD) % MOD;
            int sum_digits = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((1LL * x * sum_digits) % MOD);
        }

        return result;
    }
};
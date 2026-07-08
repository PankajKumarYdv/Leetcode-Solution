class Solution:
    MOD = int(1e9 + 7)
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)

        nonZeroCount = [0] * n
        numberUpTo = [0] * n
        digitSumUpTo = [0] * n
        pow10 = [0] * (n + 1)

        pow10[0] = 1
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % self.MOD

        nonZeroCount[0] = 1 if s[0] != '0' else 0
        numberUpTo[0] = int(s[0])
        digitSumUpTo[0] = int(s[0])

        for i in range(1, n):
            digit = int(s[i])
            nonZeroCount[i] = nonZeroCount[i - 1] + (1 if digit != 0 else 0)

        for i in range(1, n):
            digit = int(s[i])
            if digit != 0:
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % self.MOD
            else:
                numberUpTo[i] = numberUpTo[i - 1]

        for i in range(1, n):
            digitSumUpTo[i] = digitSumUpTo[i - 1] + int(s[i])

        q = len(queries)
        result = [0] * q

        for i in range(q):
            l, r = queries[i]

            startCount = 0 if l == 0 else nonZeroCount[l - 1]
            numBefore = 0 if l == 0 else numberUpTo[l - 1]

            endCount = nonZeroCount[r]
            subStrLen = endCount - startCount

            if subStrLen == 0:
                result[i] = 0
                continue

            x = (numberUpTo[r] - (numBefore * pow10[subStrLen] % self.MOD) + self.MOD) % self.MOD
            sum_digits = digitSumUpTo[r] - (0 if l == 0 else digitSumUpTo[l - 1])

            result[i] = (x * sum_digits) % self.MOD

        return result
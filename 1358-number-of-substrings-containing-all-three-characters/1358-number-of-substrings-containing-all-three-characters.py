class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        frequency_map = {"a": 0, "b": 0, "c": 0}
        res = 0
        l = 0

        for r in range(n):
            frequency_map[s[r]] += 1
            while l < r and all(frequency_map[ch] > 0 for ch in "abc"):
                res += n - r
                frequency_map[s[l]] -= 1
                l += 1

        return res

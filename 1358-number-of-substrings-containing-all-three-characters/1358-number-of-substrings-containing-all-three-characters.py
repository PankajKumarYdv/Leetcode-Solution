class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        frequencyMap = defaultdict(int)
        res = 0
        l = 0

        for r in range(n):
            frequencyMap[s[r]] += 1
            while l < r and all(frequencyMap[c] > 0 for c in ['a','b', 'c']):
                res += n-r
                frequencyMap[s[l]] -= 1
                l += 1
        return res
            
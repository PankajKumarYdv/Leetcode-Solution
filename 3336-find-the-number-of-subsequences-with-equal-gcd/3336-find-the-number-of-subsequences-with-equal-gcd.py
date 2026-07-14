class Solution:
    mod = 10**9 + 7
    def subsequencePairCount(self, nums: List[int]) -> int:
        n = len(nums)

        @lru_cache(None)
        def countPairs(i, ga, gb):
            if i == n:
                return 1 if ga == gb and ga != 0 else 0

            ans = countPairs(i + 1, ga, gb)

            if ga == 0:
                ans += countPairs(i + 1, nums[i], gb)
            else:
                ans += countPairs(i + 1, gcd(ga, nums[i]), gb)

            ans %= self.mod

            if gb == 0:
                ans += countPairs(i + 1, ga, nums[i])
            else:
                ans += countPairs(i + 1, ga, gcd(gb, nums[i]))

            return ans % self.mod

        return countPairs(0, 0, 0)
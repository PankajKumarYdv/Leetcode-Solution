class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        map = defaultdict(int)

        map[0] = 1
        count = 0
        sum = 0
        for num in nums:
            sum += num
            if (sum - k) in map:
                count += map[sum - k]
            map[sum] += 1
        return count

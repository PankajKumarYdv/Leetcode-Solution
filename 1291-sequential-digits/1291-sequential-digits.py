class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        q = deque([1, 2, 3, 4, 5, 6, 7, 8, 9])

        while q:
            num = q.popleft()
            if num > high:
                return ans
            if low <= num <= high:
                ans.append(num)
            lastDigit = num % 10
            if lastDigit < 9:
                q.append(num * 10 + lastDigit + 1)

        return ans
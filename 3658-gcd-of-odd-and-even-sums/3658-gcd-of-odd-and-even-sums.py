class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        oddSum = 0
        evenSum = 0
        flag = True
        for i in range(1,2*n):
            if flag:
                oddSum = oddSum + i
                flag = False

            else:
                evenSum = evenSum + i
                flag = True
        
        return math.gcd(oddSum, evenSum)
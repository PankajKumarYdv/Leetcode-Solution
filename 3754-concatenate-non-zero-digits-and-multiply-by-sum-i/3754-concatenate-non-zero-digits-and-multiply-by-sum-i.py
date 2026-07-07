class Solution:
    def sumAndMultiply(self, n: int) -> int:
        extracted = 0
        place = 1
        digit_sum = 0
        
        while n > 0:
            rem = n % 10
            digit_sum += rem
            
            if rem != 0:
                extracted = rem * place + extracted
                place *= 10
                
            n //= 10  # Integer division in Python
            
        return extracted * digit_sum
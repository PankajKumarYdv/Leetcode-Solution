class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort(); 
        l = score = maxScore = 0
        r = len(tokens) -1

        while l <= r:
            if power >= tokens[l]:
                power = power - tokens[l]
                score = score + 1
                l += 1
                maxScore = max(maxScore, score); 
            elif score >= 1:
                power += tokens[r]
                score -= 1; 
                r -= 1
            else :
                return maxScore 
        return maxScore 
        
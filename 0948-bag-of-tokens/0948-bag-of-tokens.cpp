class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end()); 
        int n = tokens.size()-1; 
        int l = 0; 
        int r = n; 
        int score = 0; 
        int maxScore = 0; 


        while(l <= r){
            if(power >= tokens[l]){
                power = power - tokens[l]; 
                score++; 
                l++; 
                maxScore = max(maxScore, score); 
            }else if (score >= 1){
                power = power + tokens[r];
                score--; 
                r--; 
            }else{
                return maxScore; 
            }
        }

        return maxScore; 
    }
};
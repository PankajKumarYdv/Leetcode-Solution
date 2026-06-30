class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0; 
        int rsum = 0; 
        for(int i = 0; i < k; i++){
            lsum = lsum + cardPoints[i]; 
        }

        int maxSum = lsum; 
        int r = cardPoints.size()-1; 
        k--; 

        while(k >= 0){
            lsum = lsum - cardPoints[k]; 
            k--; 
            rsum = rsum + cardPoints[r]; 
            r--; 

            maxSum = max(maxSum, (lsum + rsum)); 
        }
        return maxSum; 
    }
};
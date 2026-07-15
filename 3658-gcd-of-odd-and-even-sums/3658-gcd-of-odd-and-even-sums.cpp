class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0; 
        int evenSum = 0; 
        bool flag = true; 

        for(int i = 1; i <= (2*n); i++){
            if(flag){
                oddSum += i; 
                flag = false; 
            }else{
                evenSum += i; 
                flag = true; 
            }
        }

        return gcd(oddSum, evenSum); 

    }
};
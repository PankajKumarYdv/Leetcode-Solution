class Solution {
public:
    int firstApproach(int n){
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

    int secondApproach(int n){
        int sumOfEvenNumber = n*(n+1); 
        int sumOfOddNumber = n*n; 
        cout << "Even : " << sumOfEvenNumber << " Odd : " << sumOfOddNumber << endl; 
        return gcd(sumOfOddNumber, sumOfEvenNumber); 
    }

    int gcdOfOddEvenSums(int n) {
        // return firstApproach(n); 
        return secondApproach(n); 
    }
};
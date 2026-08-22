class Solution {
public:

    vector<int> digitSum(int num){
        int sumOfDigit = 0; 
        int sumOfProduct = 1;
         while(num > 0){
            int rem = num % 10; 
            sumOfDigit += rem ; 
            sumOfProduct *= rem; 
            num = num / 10; 
        }
        return {sumOfDigit, sumOfProduct}; 
    }

    bool checkDivisibility(int n) {
        int sumOfDigit = digitSum(n)[0]; 
        int sumOfProduct = digitSum(n)[1];
        
        cout << sumOfDigit << "," << sumOfProduct << endl; 
        if(n % (sumOfDigit + sumOfProduct) != 0){
            return false; 
        }
        return true; 
    }
};
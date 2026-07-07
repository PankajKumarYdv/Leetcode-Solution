class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0; 
        int num = n; 
        int sum = 0; 
        while(num > 0){
            int rem = num % 10; 
            sum += rem; 
            num = num / 10; 
            if(rem == 0) continue; 
            x = x * 10 + rem;
        }

        long long reversed_number = 0;
    
        while (x != 0) {
            int remainder = x % 10;
            reversed_number = reversed_number * 10 + remainder;
            x /= 10;
        }

        reversed_number = reversed_number * sum; 
        return reversed_number; 
    }
};
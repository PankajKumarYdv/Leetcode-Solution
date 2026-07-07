class Solution {
public:
    long long sumAndMultiply(int n) {
        long long extracted = 0, place = 1, sum = 0;
        
        while (n > 0) {
            int rem = n % 10;
            sum += rem;
            
            if (rem != 0) {
                extracted = rem * place + extracted; // Builds the number in original order
                place *= 10;
            }
            n /= 10;
        }
        
        return extracted * sum;
    }
};

class Solution {
public:
    int productOfNumber(int n){
        int pod = 1; 
        while(n > 0){
            int rem = n % 10; 
            pod = pod * rem; 
            n = n / 10; 
        }
        return pod; 
    }

    int smallestNumber(int n, int t) {
        int result = 0; 
        for(int i = n; i <= 100; i++){
            int productOfDigit = productOfNumber(n); 
            if(productOfDigit == 0) return n; 
            if(productOfDigit % t == 0){
                result = n; 
                break; 
            }
            n++; 
        }
        return result; 
    }
};
class Solution {
public:
    
    int fib(int n) {
        if(n==0) return 0; 
        if(n==1) return 1; 
        // vector <int> dp_array(31,-1);  
        // if(dp_array[n] != -1) return dp_array[n];
        int result = fib(n-1) + fib(n-2);
        // dp_array[n] = result; 
        return result; 
    }
};
class Solution {
public:
    // declaring vector for fixed size and default value
    vector<int> dp_array = vector<int>(31, -1); // <- This is how we declare this in class. as attrubutes. 

    int fib(int n) {
        if(n==0) return 0; 
        if(n==1) return 1; 
        if(dp_array[n] != -1) return dp_array[n];
        int result = fib(n-1) + fib(n-2);
        dp_array[n] = result; 
        return result; 
    }
};
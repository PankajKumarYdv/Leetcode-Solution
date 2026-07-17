class Solution {
public: 
    vector<int> dp_array = vector <int> (46, -1); 
    int climbStairs(int n) {
        if(n < 0){
            return 0; 
        }

        if(dp_array[n] != -1) return dp_array[n]; 

        if(n == 0){
            return 1; 
        }
        int oneStep = climbStairs(n-1); 
        int twoStep = climbStairs(n-2); 

        


        return  dp_array[n] = oneStep + twoStep;
    }
};
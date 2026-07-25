class Solution {
public:
    int maxProduct(int n) {
        int result = 0; 
        vector<int> digit; 
        while(n > 0){
            int rem = n % 10; 
            digit.push_back(rem); 
            n = n / 10; 
        }

        for(int i = 0; i < digit.size(); i++){
            for(int j = i+1; j < digit.size(); j++){
                int prod = digit[i] * digit[j]; 
                result = max(result, prod); 
            }
        }

        return result; 
    }
};
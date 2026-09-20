class Solution {
public:
    int reverseDegree(string s) {
        int result = 0; 
        int n = s.size();
        for(int i = 0; i < n; i++){
            result += (123 - s[i]) * (i+1); 
        }
        return result; 
    }
};
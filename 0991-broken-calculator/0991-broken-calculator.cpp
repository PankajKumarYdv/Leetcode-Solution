class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int o = 0; 
        if(startValue == target) return 0; 
        while(startValue != target){
            if(target % 2 == 0 && startValue < target){
                target /= 2; 
                o++; 
            }else{
                target++; 
                o++; 
            }
            
        }
        return o; 
    }
};
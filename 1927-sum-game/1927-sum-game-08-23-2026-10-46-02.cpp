class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(); 
        int sum1 = 0, sum2 = 0, quest1 = 0, quest2 = 0; 

        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?'){
                    quest1 += 1; 
                }else{
                    sum1 += num[i]-'0'; 
                }
            }else{
                if(num[i] == '?'){
                    quest2 += 1; 
                }else{
                    sum2 += num[i]-'0'; 
                }
            }
        }

        return (quest1 + quest2) % 2 == 1 || sum1 - sum2 != (quest2 - quest1)/2 * 9; 
    }
};
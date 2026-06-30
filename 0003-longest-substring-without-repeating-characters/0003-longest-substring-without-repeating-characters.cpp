class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array <int, 256> hash; 
        hash.fill(-1); 

        int n = s.size(); 
        int l = 0; 
        int r = 0; 
        int maxlen = 0; 

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1; 
                }
            }

            int len = r - l + 1; 
            maxlen = max(len, maxlen); 
            hash[s[r]] = r; 
            r++; 
        }
        return maxlen; 
    }
};
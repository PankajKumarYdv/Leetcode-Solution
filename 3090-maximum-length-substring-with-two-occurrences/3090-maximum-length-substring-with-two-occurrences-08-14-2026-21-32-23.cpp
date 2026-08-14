class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max_len = 0;
        int left = 0;
        vector<int> count(26, 0);
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;
            
            // Shrink the window if a character's count exceeds 2
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        std::vector<int> letter(26, 0); 
        
        // Count frequencies using correct ASCII indexing
        for (char c : word) {
            letter[c - 'a']++; 
        }

        // Sort frequencies in descending order (highest first)
        std::sort(letter.begin(), letter.end(), std::greater<int>()); 

        int result = 0; 
        for (int i = 0; i < 26; i++) {
            if (letter[i] == 0) break; 
            
            // First 8 get 1 push, next 8 get 2 pushes, etc.
            result += letter[i] * ((i / 8) + 1);
        }
        
        return result;
    }
};
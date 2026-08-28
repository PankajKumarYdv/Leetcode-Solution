class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int half_len = n / 2;
        
        // 1. Calculate character frequencies
        vector<int> counts(26, 0);
        for (char ch : s) {
            counts[ch - 'a']++;
        }
        
        // 2. Palindrome validation: At most one odd frequency character allowed
        string mid_char = "";
        int odd_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = string(1, (char)('a' + i));
            }
        }
        if (odd_count > 1) return ""; 
        
        // 3. Keep track of available characters for the first half
        vector<int> half_counts(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_counts[i] = counts[i] / 2;
        }
        
        string ans_half = "";
        
        // Lambda for Backtracking
        auto backtrack = [&](auto& self, int idx, bool is_greater) -> string {
            if (idx == half_len) {
                string first_half = ans_half;
                string rev_half = first_half;
                reverse(rev_half.begin(), rev_half.end());
                
                string full_palindrome = first_half + mid_char + rev_half;
                return (full_palindrome > target) ? full_palindrome : "";
            }
            
            char start_char = is_greater ? 'a' : target[idx];
            
            for (int i = start_char - 'a'; i < 26; ++i) {
                if (half_counts[i] > 0) {
                    char ch = 'a' + i;
                    half_counts[i]--;
                    ans_half.push_back(ch);
                    
                    bool next_greater = is_greater || (ch > target[idx]);
                    string res = self(self, idx + 1, next_greater);
                    
                    if (!res.empty()) return res; 
                    
                    ans_half.pop_back();
                    half_counts[i]++;
                }
            }
            return "";
        };
        
        return backtrack(backtrack, 0, false);
    }
};

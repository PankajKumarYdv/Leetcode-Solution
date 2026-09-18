class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        // Step 1: Record the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            leftmost[charIdx] = min(leftmost[charIdx], i);
            rightmost[charIdx] = i;
        }
        
        vector<string> ans;
        int last_right = -1;
        
        // Step 2 & 3: Scan the string and build intervals greedily
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            
            // Only start processing an interval at a character's first occurrence
            if (i == leftmost[charIdx]) {
                int r = rightmost[charIdx];
                bool is_valid = true;
                
                // Dynamically expand the right boundary to contain all inner character bounds
                for (int j = i; j <= r; ++j) {
                    int innerCharIdx = s[j] - 'a';
                    if (leftmost[innerCharIdx] < i) {
                        is_valid = false;
                        break;
                    }
                    r = max(r, rightmost[innerCharIdx]);
                }
                
                if (!is_valid) continue;
                
                // Greedy choice: If the current interval ends within or at the 
                // end of the previous one, replace the previous one with this smaller window.
                if (r <= last_right) {
                    ans.pop_back();
                }
                
                ans.push_back(s.substr(i, r - i + 1));
                last_right = r;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index for valid substring length calculation
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop(); // Pop the matching '(' or the base index
                
                if (st.empty()) {
                    // If stack is empty, this ')' has no matching '('
                    // Push current index as the new base for future valid substrings
                    st.push(i);
                } else {
                    // Calculate length of the current valid substring
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};

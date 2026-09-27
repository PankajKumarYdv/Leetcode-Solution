class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        
        // Pass 1: Pair up the indices of matching parentheses
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        // Pass 2: Traverse and build the final string
        string result = "";
        int direction = 1; // 1 means moving forward, -1 means backward
        
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];          // Teleport to the matching parenthesis
                direction = -direction; // Reverse our steps
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};
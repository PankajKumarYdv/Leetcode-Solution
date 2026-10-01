class Solution {
public:
    bool isValid(string s) {
        // Map to easily look up matching opening brackets
        unordered_map<char, char> matching_bracket = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        stack<char> open_brackets;
        
        for (char c : s) {
            // If the character is a closing bracket
            if (matching_bracket.count(c)) {
                // Check if stack is empty or the top doesn't match the required opening bracket
                if (open_brackets.empty() || open_brackets.top() != matching_bracket[c]) {
                    return false;
                }
                open_brackets.pop(); // Valid match found, remove from stack
            } else {
                // If it's an opening bracket, push it onto the stack
                open_brackets.push(c);
            }
        }
        
        // If the stack is empty, all brackets were correctly matched
        return open_brackets.empty();
    }
};

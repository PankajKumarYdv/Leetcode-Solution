class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Build a hash map for fast O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        int i = 0;
        int n = s.length();
        
        // Step 2: Parse the string
        while (i < n) {
            if (s[i] == '(') {
                string key = "";
                i++; // Move past '('
                
                // Extract the key inside the brackets
                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                
                // Check if the key exists in our dictionary
                if (dict.count(key)) {
                    result += dict[key];
                } else {
                    result += '?';
                }
                
                i++; // Move past ')'
            } else {
                result += s[i];
                i++;
            }
        }
        
        return result;
    }
};

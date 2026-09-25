class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> resultSet;
        dfs(expression, resultSet);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void dfs(const string& exp, set<string>& resultSet) {
        // Find the first closing brace
        size_t j = exp.find_first_of('}');
        
        // Base case: No braces left, insert the raw word
        if (j == string::npos) {
            resultSet.insert(exp);
            return;
        }
        
        // Find the matching opening brace for this closing brace
        size_t i = exp.rfind('{', j);
        
        // Split the expression into 3 sections: prefix, options inside, suffix
        string prefix = exp.substr(0, i);
        string suffix = exp.substr(j + 1);
        string inner = exp.substr(i + 1, j - i - 1);
        
        // Parse the comma-separated options inside the braces
        stringstream ss(inner);
        string option;
        while (getline(ss, option, ',')) {
            // Re-concatenate and recursively evaluate
            dfs(prefix + option + suffix, resultSet);
        }
    }
};

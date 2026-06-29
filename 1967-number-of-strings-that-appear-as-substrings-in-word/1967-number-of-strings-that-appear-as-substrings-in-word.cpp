class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (const auto& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                res++;
            }
        }
        return res;
    }
};
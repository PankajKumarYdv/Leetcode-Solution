class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> frequencyMap;
        int res = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            frequencyMap[s[r]]++;
            while (l < r && frequencyMap['a'] > 0 && frequencyMap['b'] > 0 && frequencyMap['c'] > 0) {
                res += n - r;
                frequencyMap[s[l]]--;
                l++;
            }
        }
        return res;
    }
};
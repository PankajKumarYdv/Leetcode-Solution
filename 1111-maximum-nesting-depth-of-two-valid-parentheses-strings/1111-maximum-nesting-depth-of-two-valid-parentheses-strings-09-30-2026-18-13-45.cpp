class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int depth = 0;
        
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                // Assign to subset 0 or 1 based on the current depth parity,
                // then increase the depth.
                ans[i] = depth % 2;
                depth++;
            } else {
                // Decrease the depth first to match the opening parenthesis,
                // then assign to the same subset.
                depth--;
                ans[i] = depth % 2;
            }
        }
        
        return ans;
    }
};

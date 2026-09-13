class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> nonZero1;
        vector<pair<int, int>> nonZero2;
        
        // Step 1: Store coordinates of all 1s in both images
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) nonZero1.push_back({i, j});
                if (img2[i][j] == 1) nonZero2.push_back({i, j});
            }
        }
        
        // Step 2: Count frequencies of each displacement vector
        // Map key format: "row_diff_col_diff" or use a custom hash/encoded integer
        unordered_map<string, int> vecCounts;
        int maxOverlap = 0;
        
        for (auto& p1 : nonZero1) {
            for (auto& p2 : nonZero2) {
                int rowDiff = p2.first - p1.first;
                int colDiff = p2.second - p1.second;
                string key = to_string(rowDiff) + " " + to_string(colDiff);
                
                vecCounts[key]++;
                maxOverlap = max(maxOverlap, vecCounts[key]);
            }
        }
        
        return maxOverlap;
    }
};

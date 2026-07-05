class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {-1, 0}));
        
        dp[n - 1][n - 1] = {0, 1}; // Base case: Start at 'S' (bottom-right)

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
                
                int max_score = -1, path_count = 0;
                // Check 3 choices: down, right, down-right
                for (auto& [di, dj] : { pair{1, 0}, {0, 1}, {1, 1} }) {
                    auto [next_score, next_paths] = dp[i + di][j + dj];
                    if (next_score > max_score) {
                        max_score = next_score;
                        path_count = next_paths;
                    } else if (next_score == max_score) {
                        path_count = (path_count + next_paths) % MOD;
                    }
                }
                
                if (max_score != -1) {
                    int curr_val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                    dp[i][j] = {max_score + curr_val, path_count};
                }
            }
        }
        return dp[0][0].first == -1 ? vector<int>{0, 0} : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};

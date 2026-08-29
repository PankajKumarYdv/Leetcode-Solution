class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0]; //source {0, 0}
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {

                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0) 
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};

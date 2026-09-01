
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        // Map each 'L' cell to a unique ID from 0 to litterCount - 1
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int litterCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }
        
        // If there is no litter to clean, 0 moves are needed
        if (litterCount == 0) {
            return 0;
        }
        
        int targetMask = (1 << litterCount) - 1;
        
        // max_energy[r][c][mask] stores the maximum remaining energy seen at (r, c) with `mask`
        // Initialized to -1 to represent unvisited states
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1)));
        
        // Queue stores states as: {r, c, mask, current_energy}
        queue<vector<int>> q;
        
        // Initial position setup
        int initialEnergy = energy;
        if (classroom[startX][startY] == 'R') {
            initialEnergy = energy;
        }
        
        q.push({startX, startY, 0, initialEnergy});
        max_energy[startX][startY][0] = initialEnergy;
        
        int moves = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();
                
                int r = curr[0];
                int c = curr[1];
                int mask = curr[2];
                int e = curr[3];
                
                // If all litter items are collected, return the current number of moves
                if (mask == targetMask) {
                    return moves;
                }
                
                // If we have 0 energy and we are not on a reset area, we cannot make any moves
                if (e == 0 && classroom[r][c] != 'R') {
                    continue;
                }
                
                // If we are currently on a reset area 'R', our energy gets fully restored
                if (classroom[r][c] == 'R') {
                    e = energy;
                }
                
                // Try moving in 4 directions
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirs[i];
                    int nc = c + dirs[i + 1];
                    
                    // Boundary check and obstacle check
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nextEnergy = e - 1;
                        int nextMask = mask;
                        
                        // If the next cell contains uncollected litter, collect it
                        if (classroom[nr][nc] == 'L' && litterId[nr][nc] != -1) {
                            nextMask |= (1 << litterId[nr][nc]);
                        }
                        
                        // Only proceed if this path yields strictly more energy than previously recorded
                        if (nextEnergy > max_energy[nr][nc][nextMask]) {
                            max_energy[nr][nc][nextMask] = nextEnergy;
                            q.push({nr, nc, nextMask, nextEnergy});
                        }
                    }
                }
            }
            moves++;
        }
        
        return -1; // Return -1 if it's impossible to collect all litter
    }
};
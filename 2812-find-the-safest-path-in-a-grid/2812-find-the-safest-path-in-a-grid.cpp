/*
Time Complexity: O(N^2log N)
Space Complexity : O(N^2)
*/

class Solution {
private:
    // Direction vectors for Up, Down, Left, Right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int gridSize;

    // Helper function to check if a path exists with the given safety threshold
    bool isPathSafe(const vector<vector<int>>& minThiefDist, int requiredSafety) {
        // If the starting cell itself doesn't meet the requirement, no path is possible
        if (minThiefDist[0][0] < requiredSafety) return false;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(gridSize, vector<bool>(gridSize, false));
        
        q.push({0, 0});
        seen[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Reached the bottom-right corner
            if (r == gridSize - 1 && c == gridSize - 1) return true;
            
            for (auto& d : dirs) {
                int nextRow = r + d[0];
                int nextCol = c + d[1];
                
                // Check bounds and if the cell has been visited
                if (nextRow >= 0 && nextRow < gridSize && nextCol >= 0 && nextCol < gridSize && !seen[nextRow][nextCol]) {
                    // Only traverse cells that meet the safety requirement
                    if (minThiefDist[nextRow][nextCol] >= requiredSafety) {
                        seen[nextRow][nextCol] = true;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        gridSize = grid.size();
        
        // Step 1: Precalculate shortest distance to the nearest thief for every cell
        vector<vector<int>> minThiefDist(gridSize, vector<int>(gridSize, -1));
        queue<pair<int, int>> q;
        
        // Push all thieves into the queue for Multi-Source BFS
        for (int r = 0; r < gridSize; ++r) {
            for (int c = 0; c < gridSize; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    minThiefDist[r][c] = 0;
                }
            }
        }
        
        // Radiate outward to find minimum distances
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nextRow = r + d[0];
                int nextCol = c + d[1];
                
                // If within bounds and unvisited (-1), update distance and push
                if (nextRow >= 0 && nextRow < gridSize && nextCol >= 0 && nextCol < gridSize && minThiefDist[nextRow][nextCol] == -1) {
                    minThiefDist[nextRow][nextCol] = minThiefDist[r][c] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        // Step 2: Binary Search to find the maximum possible safeness factor
        int lowSafety = 0;
        int highSafety = 2 * gridSize; // Maximum possible distance in a grid
        int maxSafenessFound = 0;
        
        while (lowSafety <= highSafety) {
            int midSafety = lowSafety + (highSafety - lowSafety) / 2;
            
            if (isPathSafe(minThiefDist, midSafety)) {
                maxSafenessFound = midSafety; // Valid path found, save result
                lowSafety = midSafety + 1;    // Try to find a larger safeness factor
            } else {
                highSafety = midSafety - 1;   // Requirement too strict, lower it
            }
        }
        
        return maxSafenessFound;
    }
};
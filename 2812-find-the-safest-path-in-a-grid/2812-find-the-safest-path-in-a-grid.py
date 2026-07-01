class Solution:
    def __init__(self):
        # Direction vectors for Up, Down, Left, Right
        self.dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        self.gridSize = 0

    def isPathSafe(self, minThiefDist: List[List[int]], requiredSafety: int) -> bool:
        # If the starting cell itself doesn't meet the requirement, no path is possible
        if minThiefDist[0][0] < requiredSafety:
            return False
        
        q = deque([(0, 0)])
        seen = [[False] * self.gridSize for _ in range(self.gridSize)]
        seen[0][0] = True
        
        while q:
            r, c = q.popleft()
            
            # Reached the bottom-right corner
            if r == self.gridSize - 1 and c == self.gridSize - 1:
                return True
            
            for dr, dc in self.dirs:
                nextRow, nextCol = r + dr, c + dc
                
                # Check bounds and if the cell has been visited
                if 0 <= nextRow < self.gridSize and 0 <= nextCol < self.gridSize and not seen[nextRow][nextCol]:
                    # Only traverse cells that meet the safety requirement
                    if minThiefDist[nextRow][nextCol] >= requiredSafety:
                        seen[nextRow][nextCol] = True
                        q.append((nextRow, nextCol))
        
        return False

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.gridSize = len(grid)
        
        # Step 1: Precalculate shortest distance to the nearest thief for every cell
        minThiefDist = [[-1] * self.gridSize for _ in range(self.gridSize)]
        q = deque()
        
        # Push all thieves into the queue for Multi-Source BFS
        for r in range(self.gridSize):
            for c in range(self.gridSize):
                if grid[r][c] == 1:
                    q.append((r, c))
                    minThiefDist[r][c] = 0
        
        # Radiate outward to find minimum distances
        while q:
            r, c = q.popleft()
            
            for dr, dc in self.dirs:
                nextRow, nextCol = r + dr, c + dc
                
                # If within bounds and unvisited (-1), update distance and push
                if 0 <= nextRow < self.gridSize and 0 <= nextCol < self.gridSize and minThiefDist[nextRow][nextCol] == -1:
                    minThiefDist[nextRow][nextCol] = minThiefDist[r][c] + 1
                    q.append((nextRow, nextCol))
        
        # Step 2: Binary Search to find the maximum possible safeness factor
        lowSafety = 0
        highSafety = 2 * self.gridSize  # Maximum possible distance in a grid
        maxSafenessFound = 0
        
        while lowSafety <= highSafety:
            midSafety = lowSafety + (highSafety - lowSafety) // 2
            
            if self.isPathSafe(minThiefDist, midSafety):
                maxSafenessFound = midSafety  # Valid path found, save result
                lowSafety = midSafety + 1     # Try to find a larger safeness factor
            else:
                highSafety = midSafety - 1    # Requirement too strict, lower it
        
        return maxSafenessFound
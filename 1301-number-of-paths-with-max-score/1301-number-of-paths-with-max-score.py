class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        MOD = 10**9 + 7
        
        # dp[i][j] stores [max_score, path_count]
        # Padded to (n+1) x (n+1) with [-1, 0] to safely handle boundary steps
        dp = [[[-1, 0] for _ in range(n + 1)] for _ in range(n + 1)]
        
        # Base case: Start at 'S' (bottom-right corner)
        dp[n - 1][n - 1] = [0, 1]
        
        # Traverse backwards from bottom-right to top-left
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if board[i][j] in ('X', 'S'):
                    continue
                
                max_score, path_count = -1, 0
                
                # Check 3 directions: down, right, and down-right diagonal
                for di, dj in ((1, 0), (0, 1), (1, 1)):
                    next_score, next_paths = dp[i + di][j + dj]
                    
                    if next_score > max_score:
                        max_score = next_score
                        path_count = next_paths
                    elif next_score == max_score and max_score != -1:
                        path_count = (path_count + next_paths) % MOD
                
                # If at least one valid path can reach this cell, update its DP value
                if max_score != -1:
                    curr_val = 0 if board[i][j] == 'E' else int(board[i][j])
                    dp[i][j] = [max_score + curr_val, path_count]
                    
        res_score, res_paths = dp[0][0]
        return [res_score if res_score != -1 else 0, res_paths]

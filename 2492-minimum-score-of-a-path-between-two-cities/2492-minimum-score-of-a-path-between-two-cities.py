class Solution:
    def dfs(self, u, adj, visited, result):
        visited[u] = True

        for v, dist in adj[u]:
            result[0] = min(result[0], dist)
            if not visited[v]:
                self.dfs(v, adj, visited, result)

    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u, v, d in roads:
            adj[u].append((v, d))
            adj[v].append((u, d))

        visited = [False] * (n + 1)
        result = [sys.maxsize]

        self.dfs(1, adj, visited, result)
        return result[0]
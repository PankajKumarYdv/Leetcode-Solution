class Solution:
    def check(self, mid: int, n: int, k: int, adj: dict) -> bool:
        result = [float('inf')] * n
        result[0] = 0

        pq = [(0, 0)]  # (distance, node)
        heapq.heapify(pq)

        while pq:
            d, node = heapq.heappop(pq)

            if d > k:
                return False

            if node == n - 1:
                return True

            if d > result[node]:
                continue

            for vec in adj.get(node, []):
                adjNode, edgeCost = vec[0], vec[1]

                if edgeCost < mid:
                    continue

                if d + edgeCost < result[adjNode]:
                    result[adjNode] = d + edgeCost
                    heapq.heappush(pq, (d + edgeCost, adjNode))

        return False

    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)
        adj = {}

        l, r = float('inf'), 0

        for edge in edges:
            u, v, w = edge
            if not online[u] or not online[v]:
                continue

            if u not in adj:
                adj[u] = []
            adj[u].append([v, w])

            l = min(l, w)
            r = max(r, w)

        answer = -1

        while l <= r:
            mid = l + (r - l) // 2

            if self.check(mid, n, k, adj):
                answer = mid
                l = mid + 1
            else:
                r = mid - 1

        return answer
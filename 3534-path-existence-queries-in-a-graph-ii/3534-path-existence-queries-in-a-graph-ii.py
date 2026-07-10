class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        sorted_pairs = [(nums[i], i) for i in range(n)]
        sorted_pairs.sort(key=lambda x: x[0])

        index_map = {idx: i for i, (_, idx) in enumerate(sorted_pairs)}

        LOG = 1
        while (1 << LOG) < n:
            LOG += 1

        up = [[0] * LOG for _ in range(n)]
        r = 0
        for l in range(n):
            if r < l:
                r = l
            while r + 1 < n and sorted_pairs[r + 1][0] - sorted_pairs[l][0] <= maxDiff:
                r += 1
            up[l][0] = r

        for j in range(1, LOG):
            for ind in range(n):
                up[ind][j] = up[up[ind][j - 1]][j - 1]

        ans = [0] * len(queries)
        for ind, (src_orig, dest_orig) in enumerate(queries):
            src = index_map[src_orig]
            dest = index_map[dest_orig]

            if src > dest:
                src, dest = dest, src

            if src == dest:
                ans[ind] = 0
                continue

            curr = src
            hops = 0
            for j in range(LOG - 1, -1, -1):
                if up[curr][j] < dest:
                    curr = up[curr][j]
                    hops += (1 << j)

            if up[curr][0] >= dest:
                ans[ind] = hops + 1
            else:
                ans[ind] = -1

        return ans
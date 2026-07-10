class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> sorted(n);
        for(int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }

        sort(sorted.begin(), sorted.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        });

        // Map each original index to its rank in the sorted order
        unordered_map<int,int> map;
        for(int i = 0; i < n; i++) {
            map[sorted[i].second] = i;
        }

        // LOG = number of binary-lifting levels needed to cover n nodes
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(n, vector<int>(LOG));

        // up[i][0] = farthest sorted index reachable in one hop from i
        int r = 0;
        for (int l = 0; l < n; l++) {
            if (r < l) r = l;                        // window can't start behind l
            while (r + 1 < n && sorted[r + 1].first - sorted[l].first <= maxDiff) r++;
            up[l][0] = r;                            // r is now as far right as l can reach
        }

        // Binary lifting table: up[ind][j] = node reached after 2^j hops from ind
        for (int j = 1; j < LOG; j++) {
            for (int ind = 0; ind < n; ind++) {
                up[ind][j] = up[up[ind][j - 1]][j - 1];
            }
        }

        vector<int> ans(queries.size());
        for(size_t ind = 0; ind < queries.size(); ind++) {
            int src = map[queries[ind][0]];
            int dest = map[queries[ind][1]];

            if(src > dest) {
                swap(src, dest); // we want to travel from left to right
            }

            if(src == dest) {
                ans[ind] = 0; // same node - no hops needed
                continue;
            }

            int curr = src;
            int hops = 0;
            // Greedily take the largest jump that still lands strictly before `dest`
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[curr][j] < dest) {
                    curr = up[curr][j];
                    hops += (1 << j);
                }
            }

            // One more hop from curr should cover `dest`; otherwise it's unreachable
            if (up[curr][0] >= dest) {
                ans[ind] = hops + 1;
            } else {
                ans[ind] = -1; // `dest` is unreachable from `src`
            }
        }

        return ans;
    }
};
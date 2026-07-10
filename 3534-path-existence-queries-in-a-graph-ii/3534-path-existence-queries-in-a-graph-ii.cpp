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

        unordered_map<int,int> map;
        for(int i = 0; i < n; i++) {
            map[sorted[i].second] = i;
        }
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(n, vector<int>(LOG));
        int r = 0;
        for (int l = 0; l < n; l++) {
            if (r < l) r = l;                      
            while (r + 1 < n && sorted[r + 1].first - sorted[l].first <= maxDiff) r++;
            up[l][0] = r;                         
        }

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
                swap(src, dest); 
            }

            if(src == dest) {
                ans[ind] = 0; 
                continue;
            }

            int curr = src;
            int hops = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[curr][j] < dest) {
                    curr = up[curr][j];
                    hops += (1 << j);
                }
            }
            if (up[curr][0] >= dest) {
                ans[ind] = hops + 1;
            } else {
                ans[ind] = -1; 
            }
        }

        return ans;
    }
};
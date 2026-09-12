class Solution {
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            if (l != other.l) return l < other.l;
            return r < other.r;
        }
    };

    struct State {
        long long weight;
        vector<int> ids;
    };

    // Helper to evaluate if path 'a' is better than path 'b'
    bool isBetter(const State& a, const State& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        // If weights are equal, choose the lexicographically smaller sorted indices list
        return a.ids < b.ids;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals by start time
        sort(arr.begin(), arr.end());

        // Precompute the next valid non-overlapping interval index for each interval
        vector<int> next_valid(n);
        for (int i = 0; i < n; ++i) {
            Interval target = {arr[i].r, 2000000000, 0, 0}; // Find first interval with l > arr[i].r
            auto it = upper_bound(arr.begin(), arr.end(), target, [](const Interval& a, const Interval& b) {
                return a.l < b.l;
            });
            next_valid[i] = distance(arr.begin(), it);
        }

        // dp[i][k] stores the best State starting from interval 'i' with 'k' choices left
        vector<vector<State>> dp(n + 1, vector<State>(5, {0, {}}));

        // Bottom-up DP processing from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip current interval
                State best = dp[i + 1][k];

                // Option 2: Take current interval
                State take = dp[next_valid[i]][k - 1];
                take.weight += arr[i].weight;
                take.ids.push_back(arr[i].id);
                // Sort indices inside to comply with lexicographical tie-breaking
                sort(take.ids.begin(), take.ids.end()); 

                if (isBetter(take, best)) {
                    best = take;
                }
                dp[i][k] = best;
            }
        }

        return dp[0][4].ids;
    }
};

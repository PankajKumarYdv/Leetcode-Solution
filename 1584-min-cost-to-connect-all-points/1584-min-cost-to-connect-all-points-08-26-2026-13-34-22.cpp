class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int Kruskal(vector<vector<int>>& vec, int V) {
        int sum = 0;
        int edgesConnected = 0;

        for (auto& temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                Union(u, v);
                sum += wt;
                edgesConnected++;

                
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        // Initialize DSU
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // 1. Generate all possible edges with Manhattan distance
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }

        // 2. Custom comparator to sort edges by weight ascending
        auto lambda = [&](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(edges.begin(), edges.end(), lambda);

        // 3. Execute Kruskal's algorithm
        return Kruskal(edges, V);
    }
};
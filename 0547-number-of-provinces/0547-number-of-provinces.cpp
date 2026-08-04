class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& matrix) {
        int V = matrix.size();

        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && matrix[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);

        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};
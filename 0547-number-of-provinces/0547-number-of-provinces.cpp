class Solution {
public:
    /* // Using DFS in Adjacency Matrix
    void dfs(int node, vector<vector<int>>& matrix, vector<bool>& visited) {
        visited[node] = true;

        int V = matrix.size();

        for (int neighbour = 0; neighbour < V; neighbour++) {
            if (matrix[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, matrix, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& matrix) {
        int V = matrix.size();

        vector<bool> visited(V, false);

        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, matrix, visited);
            }
        }

        return provinces;
    }

    */

    /*
    // Using BFS in Adjacency Matrix
    int findCircleNum(vector<vector<int>>& matrix) {
        int V = matrix.size();

        vector<bool> visited(V, false);

        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;

                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbour = 0; neighbour < V; neighbour++) {
                        if (matrix[node][neighbour] == 1 &&
                            !visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }

        return provinces;
    }
    */

    /*
    // Using DFS in Adjacency List
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<vector<int>> adj(V);

        // Matrix -> Adjacency List
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);

        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;

                bfs(i, adj, visited);
            }
        }

        return provinces;
    }
    */

    // BFS on Adjacency List
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
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
                bfs(i, adj, visited);
            }
        }

        return provinces;
    }
};
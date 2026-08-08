class Solution {
public:
    /*
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

    // Using BFS
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
};
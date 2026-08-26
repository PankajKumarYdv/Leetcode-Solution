class Solution {
public:
    typedef pair<int, int> P; // {weight, node_index}

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        // Min-heap to store {cost, node_index}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // Start with node 0 at cost 0
        
        vector<bool> inMST(V, false);
        int sum = 0;
        int edgesCount = 0; // Optimization: Stop when we have V-1 edges

        while (!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if (inMST[node] == true)
                continue;
            
            inMST[node] = true;
            sum += wt;
            edgesCount++;
            
            // Optimization: If we have visited all nodes, we can stop early
            if (edgesCount == V + 1) break; 

            // Instead of iterating an adjacency list, we iterate all other nodes
            // and calculate the Manhattan distance on the fly.
            for (int neighbor = 0; neighbor < V; neighbor++) {
                if (!inMST[neighbor]) {
                    int dist = abs(points[node][0] - points[neighbor][0]) + 
                               abs(points[node][1] - points[neighbor][1]);
                    
                    pq.push({dist, neighbor});
                }
            }
        }
        
        return sum;
    }
};
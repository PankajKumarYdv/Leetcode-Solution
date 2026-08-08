class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1; 
        pathVis[node] = 1; 

        for(int neigh : adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh, adj, vis, pathVis))
                return true; 
            }else if(pathVis[neigh]){
                return true; 
            }
        }
        pathVis[node] = 0; 
        return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]); 
        }

        vector <int> vis(numCourses, 0); 
        vector <int> pathVis(numCourses, 0); 

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)){
                    return false; 
                }
            }
        }  
        return true; 
    }
    

    /*
    bool canFinish(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V); 
        vector <int> indegree(V, 0); 

        for(auto &edge: edges){
            int u = edge[1]; 
            int v = edge[0]; 
            adj[u].push_back(v); 
            indegree[v]++;
        }

        queue <int> q; 
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0; 
        while(!q.empty()){
            int node = q.front(); 
            q.pop(); 
            count++; 
            for(int neigh : adj[node]){
                indegree[neigh]--; 
                if(indegree[neigh] == 0){
                    q.push(neigh); 
                }
            }
        }
        return count == V; 
    }
    */
};
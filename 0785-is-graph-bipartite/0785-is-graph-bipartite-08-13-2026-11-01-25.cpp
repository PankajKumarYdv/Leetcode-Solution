class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int v = adj.size(); 
        queue <int> q; 
        vector <int> color(v, -1); 
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                color[i] = 0; 
                q.push(i); 
                while(!q.empty()){
                    int u = q.front(); 
                    q.pop(); 
                    for(auto &v : adj[u]){
                        if(color[v] == -1){
                            color[v] = 1 - color[u]; 
                            q.push(v); 
                        }
                        else if(color[v] == color[u]){
                            return false; 
                        }
                    }
                }
            }
        }
        return true; 
    }
};
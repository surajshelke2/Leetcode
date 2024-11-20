class Solution {
public:
     void dfs(const vector<vector<int>>& adj, int node, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < adj.size(); i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                dfs(adj, i, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V, false);
        int count = 0;
        
        for (int i = 0; i < V; i++) { // 0-based indexing
            if (!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        
        return count;
    }
};
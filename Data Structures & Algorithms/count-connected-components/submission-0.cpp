class Solution {
public:

    void dfs(int node,
             map<int, vector<int>>& adj,
             vector<int>& visited) {

        // Mark current node as visited
        visited[node] = 1;

        // Visit all connected nodes
        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }


    int countComponents(int n, vector<vector<int>>& edges) {

        // Build adjacency list
        map<int, vector<int>> adj;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int count = 0;

        // Check every node
        for(int i = 0; i < n; i++) {

            // New component
            if(!visited[i]) {

                count++;

                // Visit entire component
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};
class Solution {
public:

    bool dfs(int node, int parent,
             map<int, vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = 1;

        for(int neighbor : adj[node]) {

            // Not visited -> explore
            if(!visited[neighbor]) {

                if(!dfs(neighbor, node, adj, visited))
                    return false;
            }

            // Visited and not parent -> cycle
            else if(neighbor != parent) {

                return false;
            }
        }

        return true;
    }


    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have n-1 edges
        if(edges.size() != n - 1)
            return false;

        map<int, vector<int>> adj;

        // Undirected graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        // Check cycle
        if(!dfs(0, -1, adj, visited))
            return false;

        // Check all nodes connected
        for(int i = 0; i < n; i++) {

            if(!visited[i])
                return false;
        }

        return true;
    }
};
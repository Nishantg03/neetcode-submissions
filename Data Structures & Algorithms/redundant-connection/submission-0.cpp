class Solution {
public:

    bool dfs(int node, int target,
             map<int, vector<int>>& adj,
             vector<int>& visited) {

        if(node == target)
            return true;

        visited[node] = 1;

        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {

                if(dfs(neighbor, target, adj, visited))
                    return true;
            }
        }

        return false;
    }


    vector<int> findRedundantConnection(
        vector<vector<int>>& edges) {

        map<int, vector<int>> adj;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            vector<int> visited(edges.size() + 1, 0);

            // Are u and v already connected?
            if(dfs(u, v, adj, visited)) {

                // Adding this edge creates a cycle
                return edge;
            }

            // No cycle, so add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
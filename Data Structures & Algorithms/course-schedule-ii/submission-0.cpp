class Solution {
public:

    bool dfs(int node, map<int, vector<int>>& adj,
             vector<int>& state, vector<int>& ans) {

        // Currently processing -> cycle
        if(state[node] == 1)
            return false;

        // Already completely processed
        if(state[node] == 2)
            return true;

        // Start processing
        state[node] = 1;

        for(int neighbor : adj[node]) {

            if(!dfs(neighbor, adj, state, ans))
                return false;
        }

        // Completely processed
        state[node] = 2;

        // Add after all dependencies are finished
        ans.push_back(node);

        return true;
    }


    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        map<int, vector<int>> adj;

        // prerequisite -> course
        for(auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {

            if(state[i] == 0) {

                if(!dfs(i, adj, state, ans))
                    return {};
            }
        }

        // DFS gives reverse topological order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
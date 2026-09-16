class Solution {
public:

    bool dfs(int node, map<int, vector<int>>& adj, vector<int>& state) {

        // Currently processing -> cycle
        if(state[node] == 1)
            return false;

        // Already completely processed
        if(state[node] == 2)
            return true;

        // Mark as currently processing
        state[node] = 1;

        for(int neighbor : adj[node]) {

            if(!dfs(neighbor, adj, state))
                return false;
        }

        // Completely processed
        state[node] = 2;

        return true;
    }


    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        map<int, vector<int>> adj;

        // Build adjacency list
        for(auto p : prerequisites) {

            int course = p[0];
            int prerequisite = p[1];

            // prerequisite -> course
            adj[prerequisite].push_back(course);
        }

        vector<int> state(numCourses, 0);

        // Check every course
        for(int i = 0; i < numCourses; i++) {

            if(state[i] == 0) {

                if(!dfs(i, adj, state))
                    return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // {distance, {x, y}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            maxHeap.push({dist, {x, y}});

            // Keep only k closest points
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;

        while (!maxHeap.empty()) {
            auto p = maxHeap.top();
            maxHeap.pop();

            ans.push_back({p.second.first, p.second.second});
        }

        return ans;
    }
};
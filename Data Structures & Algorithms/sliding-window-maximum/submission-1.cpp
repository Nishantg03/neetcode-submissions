class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    priority_queue<pair<int, int>> pq;
    vector<int> ans;

    for (int right = 0; right < nums.size(); right++) {

        // Add (value, index)
        pq.push({nums[right], right});

        // Remove elements outside current window
        while (!pq.empty() && pq.top().second <= right - k) {
            pq.pop();
        }

        // Window is ready
        if (right >= k - 1) {
            ans.push_back(pq.top().first);
        }
    }

    return ans;}
};

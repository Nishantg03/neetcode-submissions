class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {

        // Overlap
        if (intervals[i][0] <= current[1]) {

            current[0] = min(current[0], intervals[i][0]);
            current[1] = max(current[1], intervals[i][1]);

        }
        else {

            // No overlap -> current interval is finished
            result.push_back(current);

            current = intervals[i];
        }
    }

    // Add last interval
    result.push_back(current);

    return result;
}
};

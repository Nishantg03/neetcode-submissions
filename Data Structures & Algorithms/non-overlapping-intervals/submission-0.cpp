class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    int count = 0;

    vector<int> prev = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {

        // Overlap
        if (intervals[i][0] < prev[1]) {

            count++;

            // Keep the interval that ends earlier
            prev[1] = min(prev[1], intervals[i][1]);
        }

        // No overlap
        else {
            prev = intervals[i];
        }
    }

    return count;
}
};

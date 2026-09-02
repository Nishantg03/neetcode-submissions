class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    // ---------------------------------
    // Binary search for the row
    // ---------------------------------

    int left = 0;
    int right = m - 1;

    int row = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (matrix[mid][0] <= target &&
            target <= matrix[mid][n - 1]) {

            row = mid;
            break;
        }

        // Target must be in a later row
        if (matrix[mid][n - 1] < target) {
            left = mid + 1;
        }

        // Target must be in an earlier row
        else {
            right = mid - 1;
        }
    }

    // No suitable row
    if (row == -1)
        return false;


    // ---------------------------------
    // Binary search inside the row
    // ---------------------------------

    left = 0;
    right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (matrix[row][mid] == target)
            return true;

        if (matrix[row][mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}
};

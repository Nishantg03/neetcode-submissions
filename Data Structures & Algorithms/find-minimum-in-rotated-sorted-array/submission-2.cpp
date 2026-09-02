class Solution {
public:
    int findMin(vector<int> &nums) {
     int left = 0;
    int right = nums.size() - 1;

    while (left < right) {

        int mid = left + (right - left) / 2;

        // Minimum is on the right
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }

        // Minimum is on the left or at mid
        else {
            right = mid;
        }
    }

    return nums[left];}

};

class Solution {
public:

    int rob(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: Don't rob last house
        int case1 = rob(nums, 0, n - 2);

        // Case 2: Don't rob first house
        int case2 = rob(nums, 1, n - 1);

        return max(case1, case2);
    }
};
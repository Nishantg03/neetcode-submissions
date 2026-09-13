class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target,
              map<pair<int, int>, int>& dp) {

        // All elements have been used
        if (i == nums.size()) {
            if (sum == target)
                return 1;

            return 0;
        }

        // Already calculated
        if (dp.count({i, sum}))
            return dp[{i, sum}];

        // Put current number as +
        int add = solve(
            i + 1,
            sum + nums[i],
            nums,
            target,
            dp
        );

        // Put current number as -
        int subtract = solve(
            i + 1,
            sum - nums[i],
            nums,
            target,
            dp
        );

        return dp[{i, sum}] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        map<pair<int, int>, int> dp;

        return solve(0, 0, nums, target, dp);
    }
};
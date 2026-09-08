class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combination;

    void solve(vector<int>& nums, int i, int target) {

        // Target achieved
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        // No more elements
        if (i == nums.size()) {
            return;
        }

        // Option 1: Choose nums[i]
        if (nums[i] <= target) {
            combination.push_back(nums[i]);

            // Same i because we can use nums[i] again
            solve(nums, i, target - nums[i]);

            // Backtrack
            combination.pop_back();
        }

        // Option 2: Don't choose nums[i]
        solve(nums, i + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, 0, target);
        return ans;
    }
};
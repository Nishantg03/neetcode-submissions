class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& nums, int start) {

        // Every current subset is a valid answer
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            subset.push_back(nums[i]);

            // Move to next index
            solve(nums, i + 1);

            // Backtrack
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        solve(nums, 0);

        return ans;
    }
};
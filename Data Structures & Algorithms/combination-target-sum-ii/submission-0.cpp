class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& candidates, int start, int target) {

        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            // Choose
            subset.push_back(candidates[i]);

            // Move to next index because each element
            // can be used at most once
            solve(candidates, i + 1, target - candidates[i]);

            // Backtrack
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, target);

        return ans;
    }
};
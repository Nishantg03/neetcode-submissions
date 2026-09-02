class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int ct = 1;
        int ans = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1]) {
                continue;  // ignore duplicate
            }

            if (nums[i] == nums[i - 1] + 1) {
                ct++;
            }
            else {
                ct = 1;
            }

            ans = max(ans, ct);
        }

        return ans;
    }
};
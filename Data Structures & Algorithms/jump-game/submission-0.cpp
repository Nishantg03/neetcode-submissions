class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If current index is not reachable
            if (i > farthest)
                return false;

            // Update maximum reachable index
            farthest = max(farthest, i + nums[i]);

            // Already reached the last index
            if (farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};

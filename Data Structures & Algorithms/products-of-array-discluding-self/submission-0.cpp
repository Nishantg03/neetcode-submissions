class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int ct = 0;

        vector<int> output;

        // Product of all non-zero elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                p *= nums[i];
            }
            else {
                ct++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {

            // More than one zero
            if (ct > 1) {
                output.push_back(0);
            }

            // Exactly one zero
            else if (ct == 1) {
                if (nums[i] == 0)
                    output.push_back(p);
                else
                    output.push_back(0);
            }

            // No zero
            else {
                output.push_back(p / nums[i]);
            }
        }

        return output;
    }
};
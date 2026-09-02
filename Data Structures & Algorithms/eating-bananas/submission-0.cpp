class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
   int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    int ans = right;

    while (left <= right) {

        int k = left + (right - left) / 2;

        long long hours = 0;

        // Check whether k is valid
        for (int bananas : piles) {

            hours += (bananas + k - 1) / k;

        }

        if (hours <= h) {

            // k works, but maybe we can go slower
            ans = k;
            right = k - 1;

        }
        else {

            // k is too slow
            left = k + 1;
        }
    }

    return ans;   
    }
};

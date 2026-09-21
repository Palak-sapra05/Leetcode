class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int rem = num % k;

            // Start a new subarray
            newDp[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRem = (r * 1LL * rem) % k;
                newDp[newRem] += dp[r];
            }

            dp = newDp;

            // Add subarrays ending at current index
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};
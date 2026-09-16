class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(
            n + k, vector<long long>(2 * k + 1, 0)
        );

        dp[0][0] = 1;

        for (int i = 1; i <= n + k - 1; i++) {
            for (int j = 0; j <= 2 * k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[n + k - 1][2 * k];
    }
};
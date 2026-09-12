class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(a.begin(), a.end());

        // dp[i][k] = best answer from i
        // when we can still choose k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Find first interval whose start > current end
        auto findNext = [&](int i) {

            int low = i + 1;
            int high = n;

            while (low < high) {

                int mid = low + (high - low) / 2;

                if (a[mid][0] > a[i][1])
                    high = mid;
                else
                    low = mid + 1;
            }

            return low;
        };

        // DP
        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // 1. Don't take current interval
                auto notTake = dp[i + 1][k];

                // 2. Take current interval
                int next = findNext(i);

                auto take = dp[next][k - 1];

                take.first += a[i][2];
                take.second.push_back(a[i][3]);

                // Choose better score
                if (take.first > notTake.first) {

                    dp[i][k] = take;

                }
                else if (take.first < notTake.first) {

                    dp[i][k] = notTake;

                }
                else {

                    // Same score
                    sort(take.second.begin(), take.second.end());
                    sort(notTake.second.begin(), notTake.second.end());

                    // Lexicographically smaller answer
                    if (take.second < notTake.second)
                        dp[i][k] = take;
                    else
                        dp[i][k] = notTake;
                }
            }
        }

        // Get final answer
        vector<int> ans = dp[0][4].second;

        // Answer must be in increasing index order
        sort(ans.begin(), ans.end());

        return ans;
    }
};
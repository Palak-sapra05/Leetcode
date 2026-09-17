class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                // Find the shortest previous subarray
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }
            }

            // Store the shortest subarray found so far
            if (right == 0) {
                if (sum == target) {
                    best[right] = right - left + 1;
                }
            } else {
                best[right] = best[right - 1];

                if (sum == target) {
                    best[right] = min(
                        best[right],
                        right - left + 1
                    );
                }
            }
        }

        return ans == INF ? -1 : ans;
    }
};
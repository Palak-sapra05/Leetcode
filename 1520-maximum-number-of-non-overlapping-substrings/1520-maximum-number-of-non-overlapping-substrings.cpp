
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Generate valid intervals
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int start = first[c];
            int end = last[c];
            bool valid = true;

            for (int i = start; i <= end; i++) {
                int curr = s[i] - 'a';

                if (first[curr] < start) {
                    valid = false;
                    break;
                }

                end = max(end, last[curr]);
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }

        // Sort intervals by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        // Greedy selection
        for (auto &interval : intervals) {
            int start = interval.first;
            int end = interval.second;

            if (start > prevEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return ans;
    }
};
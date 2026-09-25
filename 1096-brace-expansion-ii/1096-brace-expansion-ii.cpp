class Solution {
public:
    string s;
    int i = 0;

    set<string> solve() {
        set<string> ans;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                i++;

                // Save current expression
                for (auto x : curr)
                    ans.insert(x);

                curr.clear();
                curr.insert("");
            }
            else {
                set<string> part;

                if (s[i] == '{') {
                    i++; // skip '{'
                    part = solve();
                    i++; // skip '}'
                }
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                // Concatenate curr and part
                set<string> temp;

                for (string a : curr) {
                    for (string b : part) {
                        temp.insert(a + b);
                    }
                }

                curr = temp;
            }
        }

        // Add remaining part
        for (auto x : curr)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = solve();

        return vector<string>(ans.begin(), ans.end());
    }
};
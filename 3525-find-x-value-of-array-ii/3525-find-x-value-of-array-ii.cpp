class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int i = 0; i < k; i++) {
            res.cnt[i] += a.cnt[i];
        }

        // Prefixes = whole a + prefix of b
        for (int i = 0; i < k; i++) {
            int rem = (a.prod * i) % k;
            res.cnt[rem] += b.cnt[i];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;

        int rem = val % k;

        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;

        int n = nums.size();

        // Iterative segment tree
        int size = 1;
        while (size < n)
            size <<= 1;

        vector<Node> seg(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            seg[size + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[i << 1], seg[i << 1 | 1]);
        }

        // Point update
        auto update = [&](int pos, int val) {
            int p = size + pos;

            seg[p] = makeNode(val);

            p >>= 1;

            while (p) {
                seg[p] = mergeNode(seg[p << 1], seg[p << 1 | 1]);
                p >>= 1;
            }
        };

        // Range query [l, r)
        auto query = [&](int l, int r) {
            Node left, right;

            l += size;
            r += size;

            while (l < r) {
                if (l & 1) {
                    left = mergeNode(left, seg[l]);
                    l++;
                }

                if (r & 1) {
                    --r;
                    right = mergeNode(seg[r], right);
                }

                l >>= 1;
                r >>= 1;
            }

            return mergeNode(left, right);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(index, value);

            // Possible remaining arrays are:
            //
            // [start]
            // [start ... start+1]
            // [start ... start+2]
            // ...
            // [start ... n-1]
            //
            // Therefore count prefixes with product % k == x.
            Node res = query(start, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;

        if (n >= 1000)
            cnt += n - 999;

        if (n >= 1000000)
            cnt += n - 999999;

        if (n >= 1000000000)
            cnt += n - 999999999;

        if (n >= 1000000000000LL)
            cnt += n - 999999999999LL;

        if (n >= 1000000000000000LL)
            cnt += n - 999999999999999LL;

        return cnt;
    }
};
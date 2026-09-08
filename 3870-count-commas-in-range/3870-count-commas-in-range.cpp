class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        for(int i=1000;i<=n;i++){
            cnt++;
        }
        return cnt;
    }
};
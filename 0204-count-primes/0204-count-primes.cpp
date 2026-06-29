class Solution {
public:
    int countPrimes(int n) {
        vector <bool> primes(n+1,1);
        primes[0]=primes[1]=0;
        for(int x=2;x*x<=n;x++){
            if(primes[x]==1){
                for(int y=x*x;y<=n;y+=x){
                    primes[y]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(primes[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    double myPow(double x, int n){
        // if(n==0){
        //     return 1;
        // }
        // if(n<0){
        //     return 1/myPow(x,-n);
        // }
        // return x*myPow(x,n-1);
        // return pow(x,n);
        double res=1.0;
        bool neg=0;
        long long pow=n;
        if(pow<0){
            neg=1;
            pow=abs(pow);
        }
        while(pow>0){
            if(pow & 1) res *=x;
            x*=x;
            pow >>=1;
        }
        return (neg ? (1 / res): res);
    }
};
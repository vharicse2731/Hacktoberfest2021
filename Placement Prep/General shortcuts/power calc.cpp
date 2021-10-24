#define mod 100000007

long long pow(long long a, int p)
{
    long long ans = 1;
    while(p)
    {
        if (p % 2) ans = ans * a % mod;
        a = a * a % mod;
        p /= 2;
    }
    return ans;
}

whole power:

class Solution {
public:
    double myPow(double x, int n) {
        int t=n;
        double ans=1.0;  
        while(n){
            if(n&1){
                ans*=x;
            }
            x=x*x;
            n/=2;
        }
        return t>=0?ans:1/ans;
    }
};
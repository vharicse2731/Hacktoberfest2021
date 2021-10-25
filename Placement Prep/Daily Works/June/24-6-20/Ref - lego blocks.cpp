

Ques : https://www.hackerrank.com/contests/acm-placement-dp/challenges/lego-blocks/problem

// https://www.hackerrank.com/contests/acm-placement-dp/challenges/lego-blocks/editorial

#include <iostream>
#include <cstring>
using namespace std;

const long long mod = 1000000007;
int t;
int n;
int m;
long long f[1111];
long long g[1111];
long long h[1111];

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
int main(void)
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    f[0] = 1;
    for (int i=1; i<=1000; i++)
        for (int j=1; j<=4; j++)
            if (i - j >= 0) f[i] = (f[i] + f[i-j]) % mod;

    for (cin >> t; t; t--)
    {
        cin >> n >> m;
        for (int i=1; i<=m; i++) g[i] = pow(f[i], n);

        memset(h, 0, sizeof(h));
        h[1] = 1;
        for (int i=2; i<=m; i++)
        {
            h[i] = g[i];
            long long tmp = 0;
            for (int j=1; j<i; j++)
                tmp = (tmp + h[j] * g[i-j]) % mod;
            h[i] = (h[i] - tmp + mod) % mod;
        }
        cout << h[m] << "\n";
    }

    return 0;
}
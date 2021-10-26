#include<bits/stdc++.h>
using namespace std;
bool rec(int n,int c,bool *dp)
{
    //cout<<n<<" "<<c<<endl;
    if(dp[n*2+(c%2)])
    {
        return true;
    }
    if(n==0)
    {
        if(c%2==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(c%2==0)
    {
        bool flag=false;
        for(int i=1;i*i<=n;i++)
        {
            flag=flag|rec(n-i*i,c+1,dp);
        }
        return dp[n*2+c%2]=flag;
    }
    else
    {
        bool flag=true;
        for(int i=1;i*i<=n;i++)
        {
            flag=flag&rec(n-i*i,c+1,dp);
        }
        return dp[n*2+c%2]=flag;
    }
}
bool winnerSquareGame(int n)
{
    bool dp[n+1][2];
    memset(dp,false,sizeof(dp));
    return rec(n,0,(bool *)dp);
}
int main()
{
    int n;
    cin>>n;
    cout<<winnerSquareGame(n);
    return 0;
}

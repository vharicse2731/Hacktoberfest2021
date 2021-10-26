#include<bits/stdc++.h>
using namespace std;
int fn(int arr[],int n)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=1;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(mp[t-arr[i])
        {
            c++;
            mp[arr[i]]=0;
        }
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    cout<<fn(arr,n,t);
    return 0;
}

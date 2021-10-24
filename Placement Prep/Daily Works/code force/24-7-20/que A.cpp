#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        string ans[n+1];
        ans[0]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
        for(int i=1;i<=n;i++)
        {
            int len=a[i-1];
            for(int j=0;j<len;j++)
            {
                ans[i].push_back(ans[i-1][j]);
            }
            for(int j=len;j<ans[i-1].size();j++)
            {
                if(ans[i-1][j]=='z')
                {
                    ans[i].push_back('a');
                }
                else
                {
                    ans[i].push_back(ans[i-1][j]+1);
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            cout<<ans[i]<<endl;
        }
    }
}

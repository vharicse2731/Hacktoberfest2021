#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n;
        long long int k;
        cin>>n>>k;
        vector<pair<long long int,int>>v;
        for(int i=0;i<n;i++)
        {
            long long int u;
            cin>>u;
            v.push_back(make_pair((u-1)/k,i+1));
        }
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }

        cout<<"Case #"<<tc<<": ";
        for(int i=0;i<n-1;i++)
        {
            cout<<v[i].second<<" ";
        }
        cout<<v[n-1].second<<endl;
    }
    return 0;
}

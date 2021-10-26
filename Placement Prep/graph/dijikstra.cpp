#include<bits/stdc++.h>
using namespace std;
void shortest(vector<pair<int,long long int>>adj[],int src,int n)
{
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
    long long int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            long long int w=(*it).second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,long long int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        adj[u-1].push_back(make_pair(v-1,w));
        adj[v-1].push_back(make_pair(u-1,w));
    }
    shortest(adj,0,n);
    return 0;
}

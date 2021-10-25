

/*

Given N nodes and M edges.
M lines... give a edge (u-v)

Two nodes A and B are said to be connected if either they have a telephone line(an edge) 
between them or there exists a node C such that A is connected to C 
and also B is connected to C.

The graph is initially a connected graph 
i.e,for each pair of nodes there is direct(single telephonic line) or 
indirect telephonic line(series of telephonic line) connection between them.

Now, the telephonic lines are starting to break-down in the 
order they are provided in the input ,i.e, at i-th moment some previously 
existing connection A-B  breaks.
And finally at the end,there will be no telephone line among any of the nodes.


Total sadness at a moment is defined as the total number of unordered node pairs  
(A,B) such that A and B are not connected at that moment (they are disconnected).

After each telephone line (edge) breakup, 
you have to tell the total sadness among the nodes at the moment.

Note : The graph does not contain multiple edges or self loops.

I/P:
3 2
1 2
2 3

O/P:
2
3

Expl:

Initially all the nodes are connected. (1,2) and (2,3) are connected directly 
while (1,3) are connected indirectly.

First, edge-1 (1-2) is removed. After removal of first edge, 
only (2,3) remains connected while (1,2) and (1,3) are disconnected. 
So there are two disconnected unordered pair of nodes (i.e. (1,2) and (1,3))

Second, edge-2 (2,3) is removed, after which the only connected pair of nodes in the graph 
also gets disconnected. So, now there are three 
disconned unordered pair of nodes (i.e. (1,2) ,(1,3)  and (2,3) ).

*/

// https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/sadness/problem

#include<bits/stdc++.h>
using namespace std;
vector<long long>par,sz;
int find(int x){
    while(x!=par[x])
        x=par[x];
    return x;
}
long long join (int x,int y){
    int i=find(x);
    int j=find(y);
    if(i==j)
        return 0;
    long long res=sz[i]*sz[j];
    if(sz[i]>=sz[j]){
        sz[i]+=sz[j];
        par[j]=i;
    }
    else{
        sz[j]+=sz[i];
        par[i]=j;
    }
    return res;
}
int main() {
    long v;int e;
    cin>>v>>e;
    par=vector<long long >(v);
    for(int i=0;i<v;i++){
        par[i]=i;
    }
    sz=vector<long long>(v,1);
    vector<pair<int,int>>arr(e);
    
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;x=x-1;arr[i].first=x;
        y=y-1;arr[i].second=y;
    }
    vector<long long>ans(e);
    ans[e-1]=(v*(v-1))/2;
    for(int i=e-1;i>=1;i--){     
        ans[i-1]=ans[i]-join(arr[i].first,arr[i].second);
    }
    for(auto a:ans)
        cout<<a<<endl;
    return 0;
}
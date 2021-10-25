
// https://www.spoj.com/problems/PT07Z/

// longest path btw 2 nodes in tree topology of graph

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],vector<bool>&vis,int i,int cur,int *maxi,int *maxs){
//cout<<i;
    if(*maxs < cur){
        *maxs=cur;
        *maxi=i;
    }
    vis[i]=true;
    for(auto a:g[i]){
        if(!vis[a])
            dfs(g,vis,a,cur+1,maxi,maxs);
    }
}

void solve(){
    int V,u,v;
	cin>>V;
	vector<int>g[V];
	vector<bool> vis(V,false);
	
	for(int i=0;i<V-1;i++){
	    cin>>u>>v;
	    g[u-1].push_back(v-1);
	    g[v-1].push_back(u-1);
	}
	
	int max=INT_MIN,maxi=0,maxs=0;
	dfs(g,vis,0,0,&maxi,&maxs);
//	cout<<maxi<<" "<<maxs<<endl;
	vis.assign(vis.size(),false);

	maxs=0;
	dfs(g,vis,maxi,0,&maxi,&maxs);
	cout<<maxs<<endl;
}
int main() {
    solve();
	return 0;
}
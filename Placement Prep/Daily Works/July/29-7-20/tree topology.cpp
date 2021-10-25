
// Tree topology
// https://www.spoj.com/problems/PT07Y/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],vector<bool>&vis,int i,bool *ok,int par){
    if(*ok == false)
        return;
    vis[i]=true;
    for(auto a:g[i]){
        if(!vis[a])
            dfs(g,vis,a,ok,i);
        else if(a!=par)
            *ok = false;
    }
}

bool solve(){
    int V,e,u,v;
	cin>>V>>e;
	if(V!=e+1)
	    return 0;
	vector<int>g[V];
	vector<bool> vis(V,false);
	for(int i=0;i<e;i++){
	    cin>>u>>v;
	    g[u-1].push_back(v-1);
	    g[v-1].push_back(u-1);
	}
	
	bool ok=true;
	dfs(g,vis,0,&ok,-1);
	
	if(!ok){
//	    cout<<"Ok cond";
	    return 0;
	}
	for(bool a : vis)
	    if(a==false){
//	        cout<<"vis cond.";
	        return 0;
	    }
	        
	return true;
}
int main() {
    if(solve())
	    cout<<"YES";
	else
	    cout<<"NO";
	cout<<endl;
	return 0;
}
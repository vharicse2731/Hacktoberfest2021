
https://practice.geeksforgeeks.org/problems/knight-walk/0

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool issafe(int i,int j,int m,int n){
    if(i>0 && i<=m && j>0 && j<=n)
        return true;
    return false;
}
int x[8]={-1,-2,-1,-2,1,2,1,2};
int y[8]={-2,-1,2,1,-2,-1,2,1};

int main()
 {
    int t,m,n;
    cin>>t;
    while(t--){
	    cin>>m>>n;
	    int arr[m+1][n+1];
	    bool vis[m+1][n+1];
	    
	    for(int i=0;i<=m;i++)
	        for(int j=0;j<=n;j++)
	            arr[i][j]=-1;
	    for(int i=0;i<=m;i++)
	        for(int j=0;j<=n;j++)
	            vis[i][j]=false;
	    int d1,d2;
	    cin>>d1>>d2;
	    arr[d1][d2]=0;
	    queue<pair<int,int>> q;
	    q.push(make_pair(d1,d2));
	    cin>>d1>>d2;
	    while(!q.empty()){
	        auto it=q.front();
	        vis[it.first][it.second]=true;
	        if(it.first==d1 && it.second==d2)
	            break;
	        q.pop();
	        for(int k=0;k<8;k++){
	            if(issafe(it.first+x[k],it.second+y[k],m,n) && !vis[it.first+x[k]][it.second+y[k]]){
	                arr[it.first+x[k]][it.second+y[k]]=arr[it.first][it.second]+1;
	                q.push(make_pair(it.first+x[k],it.second+y[k]));
	            }
	        }
	    }
	    cout<<arr[d1][d2]<<endl;
	}
	return 0;
}
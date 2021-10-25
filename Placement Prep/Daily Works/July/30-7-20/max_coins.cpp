

//  https://www.spoj.com/problems/COINS/

// COINS - Bytelandian gold coins

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
map<int,long int>mp;

long int ans(int a){
    if(a==0)
        return 0;
    long int i=mp[a];
    if(i==0){
        mp[a]=max((long int)a,ans(a/2)+ans(a/3)+ans(a/4));
    }
    return mp[a];
}

int main() {
	int n;
	while(scanf("%d",&n)!=EOF){
	    cout<<ans(n)<<endl;
	}
	return 0;
}
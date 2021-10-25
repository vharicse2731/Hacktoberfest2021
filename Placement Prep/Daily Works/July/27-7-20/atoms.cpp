
// https://www.spoj.com/problems/ATOMS/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    unsigned long long int n,k,m;
    cin>>n>>k>>m;
    int time=0;
    if(m>n){
    while(m/n >=k){
        time++;
        n*=k;
    }
    }
    cout<<time<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
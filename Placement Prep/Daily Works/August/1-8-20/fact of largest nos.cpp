

//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,c;
    cin>>n;
    vector<int>ans;
    ans.push_back(1);
    for(int i=2;i<=n;i++){
        c=0;
        for(int x=0;x<ans.size();x++){
            ans[x]=ans[x]*i+c;
            c=ans[x]/10;
            ans[x]=ans[x]%10;
        }
        while(c){
            ans.push_back(c%10);
            c=c/10;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
	    solve();
	    cout<<endl;
	}
	return 0;
}
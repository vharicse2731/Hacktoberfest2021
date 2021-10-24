
// https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

#include<iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    while(n>0){
        if(n&1)
            n--;
        else
            n/=2;
        ans++;
    }
    cout<<ans<<endl;
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
	    solve();
	}
	return 0;
}
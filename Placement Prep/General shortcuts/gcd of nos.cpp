
//GCD of Nos.
/*
Gcd of 2 numbers doesn't vary if we subtract the small one from bigger one. so by doing it 
recursively ... 
if(a==0) return b;
if(b==0) return a;
if(a==b) return a;
if(a>b) return gcd(a-b,b);
return gcd(a,b-a);
*/



#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}
void solve(){
    int n;
    cin>>n;
    int ans,a;
    cin>>ans;
    n--;
    while(n--){
        cin>>a;
        ans=gcd(ans,a);
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
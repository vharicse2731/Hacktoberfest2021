

/*
No. of trailing zeros in a factorial.
o(log n) so.
*/

//https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial/0

#include<iostream>
using namespace std;
long long solve(){
    long long x,ans=0;
    cin>>x;
    for(long long i=5;(x/i)>0;i=i*5)
        ans+=x/i;
    return ans;
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
	    cout<<solve()<<endl;
	}
	return 0;
}
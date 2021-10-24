
// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

#include<iostream>
using namespace std;
int solve(){
    int n,num,ans;
    cin>>n;
    
    if(n&1)
        ans=((n+1)/2)*n;
    else
        ans=(n/2)*(n+1);

    for(int i=0;i<n-1;i++){
        cin>>num;
        ans-=num;
    }
    return ans;
}
int main()
 {
    int t,i,n;
    cin>>t;
    while(t--){
	    cout<<solve()<<endl;
	}
	return 0;
}
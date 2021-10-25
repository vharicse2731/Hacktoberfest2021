

//Total no. of unique BST
// https://practice.geeksforgeeks.org/problems/unique-bsts/0

// FOr BT : (ans*n!);  

// catayon no. = (2n)!/(n!*(n+1)!)
// for BT = (catayon no.)*n!;

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i]+=dp[i-j]*dp[j-1];
    return dp[n];
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
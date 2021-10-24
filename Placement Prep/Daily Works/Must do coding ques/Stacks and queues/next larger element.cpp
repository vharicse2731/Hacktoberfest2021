
// https://practice.geeksforgeeks.org/problems/next-larger-element/0

/*
Maintaining stacks to keep track of the next largest element.. if larger element occurs
at tos, print it..else pop untill it reaches --> shows cur is largest of all till now from back.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    long long int arr[n];
    long long int ans[n];
    stack<long long int>st;
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    st.push(arr[n-1]);
    ans[n-1]=-1;
    
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[i]>=st.top())
            st.pop();
        if(st.empty()){
            ans[i]=-1;
        }
        else 
            ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
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

https://practice.geeksforgeeks.org/problems/stock-span-problem/0

#include<iostream>
using namespace std;
int main()
 {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    if(n==1)
	        cout<<1<<endl;
	    else{
	        cout<<1<<" ";
	        int count;
	        for(int i=1;i<n;i++){
	            count=1;int j=i-1;
	            while(j>=0 && arr[j]<=arr[i]){
	                count++;j--;
	            }
	           cout<<count<<" ";
	        }
	        cout<<endl;
	    }
	
	}
	return 0;
}
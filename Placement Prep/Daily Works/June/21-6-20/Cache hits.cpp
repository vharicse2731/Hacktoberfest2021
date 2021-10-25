

https://www.codechef.com/COOK119B/problems/CACHEHIT/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
	// your code goes here
	int n,b,m,t;
	cin>>t;
	
	while(t--){
	    
	    cin>>n>>b>>m;
	    int arr[m];
	    
	    for(int i=0;i<m;i++){
	        cin>>arr[i];
	    }
//	    if(m>0){
	  //  int block[n];
	   // memset(block,0,sizeof(block));
//	    int k=0;
	    
	   // for(int i=0;i<n;){
	   //     block[i]=k;i++;
	   //     while(i<n && (i%b) !=0 ){
	   //         block[i]=k;
	   //         i++;
	   //     }
	   //     k++;   
	   // }
	        
	    int prev=arr[0]/b ;
	    int count=1;
	    for(int i=1;i<m;i++){
	        if(prev!= arr[i]/b){
	            count++;
	            prev=arr[i]/b;
	        }
	    }
	    
	    cout<<count<<endl;
//	    }
//	    else
//	        cout<<0<<endl;
	   // for(int i=0;i<n;i++)    
	   //     cout<<block[i]<<" ";
	   // cout<<endl;
	   
	}
	return 0;
}

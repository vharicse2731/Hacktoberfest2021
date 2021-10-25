
//  https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int x[4]={0,1,0,-1};
// int y[4]={1,0,-1,0};
int main()
 {
    int t,m,n;
    cin>>t;
    while(t--){
	    cin>>m>>n;
	    int arr[m][n];
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++)
	            cin>>arr[i][j];
	    }
	    
	    int up=0,down=m-1,left=0,right=n-1;
	    
	    while(up<=down && left<=right){
	        
	        for(int i=left;i<=right;i++){
	            cout<<arr[up][i]<<" ";
	        }
	        up++;
	        
	        for(int i=up;i<=down;i++){
	            cout<<arr[i][right]<<" ";
	        }
	        right--;
	        
	        if(up<=down){
	            for(int i=right;i>=left;i--){
	                cout<<arr[down][i]<<" ";
	            }
	            down--;
	        }
	        
	        if(right>=left){
	            for(int i=down;i>=up;i--){
	                cout<<arr[i][left]<<" ";
	            }
	            left++;
	        }
	        
	    }
	    cout<<endl;
	}
	return 0;
}
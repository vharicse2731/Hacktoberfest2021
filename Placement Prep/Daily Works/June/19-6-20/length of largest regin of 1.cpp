
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int x[8]={-1,0,1,0,-1,1,1,-1};
int y[8]={0,-1,0,1,-1,1,-1,1};

bool issafe(int m,int n,int i,int j){
 //   cout<<"m;"<<i<<" n;"<<j<<"--->";
    if(i>=0 && i<m && j>=0 && j<n)
        return true;
    return false;
}
void findmax(int l,int m,vector<vector<int>> &arr,int *count){
//    cout<<"l:"<<l<<" m:"<<m<<endl;
    arr[l][m]=0;
    for(int k=0;k<8;k++){
        if(issafe(arr.size(),arr[0].size(),l+x[k],m+y[k])){
//            cout<<endl<<l+x[k]<<" "<<m+y[k];
            if(arr[l+x[k]][m+y[k]]==1){
//                cout<<" "<<l+x[k]<<" "<<m+y[k]<<endl;
                (*count)++;
                findmax(l+x[k],m+y[k],arr,count);
            }
        }
    }
}

int main()
 {
    int t,m,n;
    cin>>t;
    while(t--){
	    
	    cin>>m>>n;
	    vector<vector<int>> arr(m);
	    // vector<int>arr(n,vector<int>(m,0));
	    for(int i=0;i<m;i++){
	        arr[i]=vector<int>(n);
	        for(int j=0;j<n;j++)
	            cin>>arr[i][j];
	    }
//	    cout<<"m:"<<arr.size()<<" n:"<<arr[0].size()<<endl;
	   // for(int i=0;i<m;i++){
	   //     for(int j=0;j<n;j++)
	   //         cout<<arr[i][j]<<" ";
	   //     cout<<endl;
	   // }
	    
	    int max=0,count=0;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(arr[i][j]==1){
//	                cout<<"call"<<endl;
	                count=1;
	                findmax(i,j,arr,&count);
	               // for(int i=0;i<m;i++){
	               //     for(int j=0;j<n;j++)
	               //         cout<<arr[i][j]<<" ";
	               //     cout<<endl;
	               // }
	                if(max<count)   
	                    max=count;
	            }
	        }
	    }
	    cout<<max<<endl;
	}
	return 0;
}
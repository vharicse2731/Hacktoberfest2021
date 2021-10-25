
https://www.hackerrank.com/contests/acm-placement-dp/challenges/superman-celebrates-diwali


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,h,k,nh,temp;
    
    cin>>n>>h>>k;
    vector<int>dp(h+1,0);
    int arr[n+1][h+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        cin>>nh;
        for(int j=1;j<=nh;j++){
            cin>>temp;
            arr[i][temp]+=1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=h;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
        dp[1]=max(dp[1],arr[i][1]);
    for(int j=2;j<=h;j++){
        for(int i=1;i<=n;i++){
            if(j-k >0){
      //           int maxi=0;
      //           for(int l=1;l<=n;l++){
      //               if(l!=i)
      //                   maxi=max(maxi,arr[l][j-k]);
      //           }
      // //          cout<<endl<<"maxi:"<<maxi<<endl;
      //           arr[i][j]=max(arr[i][j]+arr[i][j-1],arr[i][j]+maxi);
                arr[i][j]=max(arr[i][j]+arr[i][j-1],arr[i][j]+dp[j-k]); 
            }
            else
                arr[i][j]=arr[i][j]+arr[i][j-1];
            dp[j]=max(dp[j],arr[i][j]);
        }
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=h;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int maxi=0;
   
    for(int i=1;i<=n;i++){
        maxi=max(maxi,arr[i][h]);
    }
    cout<<maxi;
    
    return 0;
}

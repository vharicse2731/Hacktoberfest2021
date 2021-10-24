#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,num;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>num;
        arr[i][2]=num%10;
        num/=10;
        arr[i][1]=num%10;
        num/=10;
        arr[i][0]=num%10;
        sort(arr[i].begin(),arr[i].end());
        arr[i][2]=arr[i][2]*11+arr[i][0]*7;
        arr[i][1]=arr[i][2]%10;
        arr[i][2]/=10;
        arr[i][0]=arr[i][2]%10;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<" ";
    // }
    vector<int>ans(10);
    num=0;
    
    for(int i=0;i<n;i=i+2){
        ans[arr[i][0]]++;
    }
    for(int i=0;i<10;i=i+2){
        if(ans[i]==2)
            num++;
        else if(ans[i]>2)
            num+=2;
    }
    
    for(int i=0;i<10;i++){
        ans[i]=0;
    }
    
    for(int i=1;i<n;i=i+2){
        ans[arr[i][0]]++;
    }
    for(int i=1;i<10;i=i+2){
        if(ans[i]==2)
            num++;
        else if(ans[i]>2)
            num+=2;
    }
    
    cout<<num;
}
int main() {
    solve();
	return 0;
}
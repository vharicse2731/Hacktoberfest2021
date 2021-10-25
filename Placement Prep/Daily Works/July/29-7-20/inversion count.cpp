
// https://www.spoj.com/problems/INVCNT/

// No. of steps to sort the array

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long int merge(vector<int> &arr,vector<int> &temp,int l,int mid,int h){
    int i=l,j=mid,k=l; long int inv=0;
    while(i<mid && j<=h){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv+=mid-i;
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=h){
        temp[k++]=arr[j++];
    }
    for(int i=l;i<=h;i++)
        arr[i]=temp[i];
    return inv;
}

long int mergesort(vector<int> &arr,vector<int> &temp,int l,int h){
    long int inv=0;int mid;
    if(l<h){
        mid=l+(h-l)/2;
        inv+=mergesort(arr,temp,l,mid);
        inv+=mergesort(arr,temp,mid+1,h);
        inv+=merge(arr,temp,l,mid+1,h);
    }
    return inv;
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &a:arr)
        cin>>a;
    vector<int>temp(n);
    cout<<mergesort(arr,temp,0,n-1)<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}
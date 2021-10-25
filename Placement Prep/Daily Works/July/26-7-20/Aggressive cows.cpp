

//  Aggressive cows

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&arr,int &mid,int &c){
	int cur=arr[0];
	int count=1;
	for(int i=1;i<arr.size();i++){
		if(arr[i]-cur >= mid){
			cur=arr[i];
			count++;
			if(count==c)
				return true;
		}
	}
	return false;
}

int main() {
	int t,n,c;
	cin>>t;
	while(t--){
		cin>>n>>c;
		vector<int>arr(n);
		for(int &a : arr)
			cin>>a;
		sort(arr.begin(),arr.end());
		int l=0,h=arr[n-1],mid,md=-1;
		
		while(l<h){
			mid=l+(h-l)/2;
			if(!check(arr,mid,c)){
				h=mid;
			}
			else{
			    if(md<mid)
			        md=mid;
				l=mid+1;
			}
		}
		cout<<md<<endl;
	}
	return 0;
}
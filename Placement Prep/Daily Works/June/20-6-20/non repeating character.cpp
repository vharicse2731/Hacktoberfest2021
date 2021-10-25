
//  https://practice.geeksforgeeks.org/problems/non-repeating-character/0

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
 {
    int t,n;
    cin>>t;
    char a;
    while(t--){
	    cin>>n;
	    string str;
	    cin>>str;
//	    cout<<str<<endl;
	    unordered_map<char,int> mp;
	    for(int i=0;i<str.size();i++){
	  
	        mp[str[i]]++;
	    }
	    bool flag=true;
	    for(int i=0;i<str.size();i++){
	        if(mp[str[i]]==1){
	            cout<<str[i]<<endl;flag=false;break;
            }
	    }
	    if(flag)
	        cout<<-1<<endl;
	}
	return 0;
}
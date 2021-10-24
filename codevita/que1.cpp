#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s2[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[s1[i]]>0)
            mp[s1[i]]--;
        else
            return n-i;
    }
    return 0;
}
int main() {
    cout<<solve();
	return 0;
}
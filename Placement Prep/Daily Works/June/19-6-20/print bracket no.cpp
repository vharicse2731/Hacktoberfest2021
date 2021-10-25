
https://practice.geeksforgeeks.org/problems/print-bracket-number/0

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
 {
    int t;
    cin>>t;
    while(t--){
	    string str;
	    cin>>str;
	    stack<int>s;
	    int k=1;
	    for(int i=0;i<str.size();i++){
	        if(str[i]=='('){
	            s.push(k);
	            cout<<k<<" ";
	            k++;
	        }
	        else if(str[i]==')'){
	            cout<<s.top()<<" ";s.pop();
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
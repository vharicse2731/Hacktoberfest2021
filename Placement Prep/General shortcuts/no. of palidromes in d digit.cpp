

// No. of palindromes on n digit nos.

// 1/pow(10,n/2);
// total no. of numbers in n digit is pow(10,n)
// no. of palindromes --> even = pow(10,n/2) --> odd = pow(10,(n+1)/2)

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    n=n/2;
	    cout<<"1 1";
	    for(int i=0;i<n;i++)
	        cout<<"0";
	    cout<<endl;
	}
	return 0;
}


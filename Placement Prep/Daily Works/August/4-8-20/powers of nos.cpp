

/*
Power of numbers :
i/p:
N

find pow(N,R);
 --> R=reverse of N;
*/


// https://practice.geeksforgeeks.org/problems/power-of-numbers/0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long int call (long long a,long long p){
    long long res=1;
    a=a%mod;
    while(p){
        if(p&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        p=p/2;
    }
    return res;
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
        string num,rev;
	    cin>>num;
	    rev=num;
	    reverse(rev.begin(),rev.end());
	    cout<<call(stoll(num),stoll(rev))<<endl;
	}
	return 0;
}
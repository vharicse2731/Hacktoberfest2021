
https://practice.geeksforgeeks.org/problems/lucky-alive-person-in-a-circle/0

#include<iostream>
using namespace std;
int main()
 {
    int t,n;
    cin>>t;
    while(t--){
	    cin>>n;
	    int k=1;
	    while(k<=n)
	        k=k<<1;
	    k=k>>1;
	    cout<<(n-k)*2+1<<endl;
	
	}
	return 0;
}

kth person

int remaining(int n, int k) {
    int r = 0;
    for (int i = 2; i <= n; i++)
        r = (r + k) % i;

    return r;
}
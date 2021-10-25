
// https://practice.geeksforgeeks.org/problems/excel-sheet-part-2/0
// exceel sheet -2 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;string s;
    cin>>t;
    while(t--){
	    cin>>s;long long int ans=0;
	    for(int i=0;i<s.size();i++)
	        ans=ans*26+(s[i]-64);
	    cout<<ans<<endl;
	}
	return 0;
}

ALITER:

int titleToNumber(string s) {
        int ans=0;
        for(char a:s){
            ans=ans*26+(a-'A'+1);
        }
        return ans;
    }
	
	
// REVERSE 

int main()
 {
    int t,n;
    cin>>t;
    vector<char>ans;
    while(t--){
        ans.clear();
	    cin>>n;
	    while(n>0){
	        n--;
	        ans.push_back('A'+n%26);
	        n/=26;
	    }
	    reverse(ans.begin(),ans.end());
	    for(char a:ans)
	        cout<<a;
	    cout<<endl;
	}
	return 0;
}

// SIMPLE:
return number==0?"":title((number-1)/26)+(char)((number-1)%26+'A');
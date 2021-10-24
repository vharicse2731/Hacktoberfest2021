
// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    cin>>str;
    stringstream s(str);
    stack<string>st;
    while(getline(s,str,'.')){
        st.push(str);
    }
    int n=st.size();
    while(n!=1){
        cout<<st.top()<<".";
        n--;
        st.pop();
    }
    cout<<st.top()<<endl;
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
	    solve();
	}
	return 0;
}

// https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

USING STACK:


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool solve(){
    string str;
    cin>>str;
    stack<char>st;
    for(char a:str){
        if(a=='(' || a=='{' || a=='['){
            st.push(a);continue;
        }
        if(st.empty())
            return 0;
        else if(a==')'){
            if(st.top()!='(')
                return 0;
            else
                st.pop();
        }
        else if(a=='}'){
            if(st.top()!='{')
                return 0;
            else
                st.pop();
        }
        else{
            if(st.top()!='[')
                return 0;
            else
                st.pop();
        }
    }
    if(!st.empty())
        return 0;
    return 1;
}
int main()
 {
    int t;
    cin>>t;
    while(t--){
	    if(solve())
	        cout<<"balanced";
	    else
	        cout<<"not balanced";
	    cout<<endl;
	}
	return 0;
}


USING RECURSIVE MANNER :
/*
{[[()]]}
1 : {[[]]}
2 : {[]}
3 : {}
4 : "" --> true if not empty false;
*/

bool isValid(string s) {
        if(s == "") return true;
             
        int previousSize = 0;
        int currentSize = s.size();
        while(!s.empty()){
            if(previousSize == currentSize) return false;
            previousSize = s.size();
            
            for(int i = 0; i < s.size()-1; ++i){
                if((s[i] == '[' && s[i+1] == ']') || (s[i] == '{' && s[i+1] == '}') || (s[i] == '(' && s[i+1] == ')')){
                    s.erase(i, 2);
                    i -= 2;
                }
            }
            
            currentSize = s.size();
        }
        
        return true;
    }
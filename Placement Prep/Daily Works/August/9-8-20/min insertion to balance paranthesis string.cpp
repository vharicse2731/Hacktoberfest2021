

//https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

/*
for a '(' must have 2 corresponding  ')' ie., --> '(' - '))' 
*/

ITERATIVE :

class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int manualadd=0,reqclose=0;
        for(char a:s){
            if(a=='('){
                reqclose+=2;
                if(reqclose%2==1){
                    manualadd++;
                    reqclose--;
                }
            }
            else{
                if(reqclose==0){
                    manualadd++;
                    reqclose++;
                }
                else
                    reqclose--;
            }
        }
        return manualadd+reqclose;
    }
};



USING STACKS:

class Solution {
public:
    int minInsertions(string s) {
        int ans=0,n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(s[i]);
            else{
                if(i+1 < n && s[i]==s[i+1])
                    i++;
                else
                    ans++;
                if(st.empty())
                    ans++;
                else
                    st.pop();
            }
        }
        return ans+st.size()*2;
    }
};



// Mine --> not work fine --> not works for only consecutive closed brackets... ;(((

class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;int ans=0;
        for(char a:s){
            if(st.empty() && a==')'){
                st.push(a);
            }
            else if(a=='(')
                st.push(a);
            else{
                if(st.top()==')'){
                    st.pop();
                    if(st.empty())
                        ans++;
                    else
                        st.pop();
                }
                else
                    st.push(a);
            } 
        }
        char a,b;
        while(!st.empty()){
            a=st.top();
            st.pop();
            if(a==')'){
                if(st.empty()){
                    ans+=2;
                }
                else{
                    if(st.top()=='('){
                        ans++;st.pop();
                    }
                    else{
                        b=st.top();
                        st.pop();
                        if(st.empty()) 
                            ans++;
                        else if(st.top()!='(')
                            ans++;
                        else
                            st.pop();
                            
                    }
                }
            }
            else if(a=='(')
                ans+=2;
        }
        return ans;
    }
};
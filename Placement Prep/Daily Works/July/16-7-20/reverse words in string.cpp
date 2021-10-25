



// https://leetcode.com/problems/reverse-words-in-a-string/

Sol 1:
class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        stack<string>st;
        
        while(str>>s){
            st.push(s);
        }
        
        s="";
        if(!st.empty()){
            s+=st.top();
            st.pop();
        }
        while(!st.empty()){
            s+=' ';
            s+=st.top();
            st.pop();
        }
        return s;
    }
};


Sol 2:

class Solution {
public:
    string reverseWords(string s) {
        string str;stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                continue;
            
            str="";
            
            while(i<s.size() && s[i]!=' '){
 //               cout<<s[i]<<"&";
                str+=s[i];i++;
            }
//            cout<<str<<endl;
            st.push(str);
        }
        
        s="";
        if(!st.empty()){
            s+=st.top();
            st.pop();
        }
        while(!st.empty()){
            s+=' ';
            s+=st.top();
            st.pop();
        }
        return s;
    }
};
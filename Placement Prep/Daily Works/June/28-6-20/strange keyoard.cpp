
// https://www.hackerrank.com/contests/hack-the-interview-v-asia-pacific/challenges/strange-keyboard-1/problem
You have bought a new strange keyboard. When you press the   key, you cannot use any number. And sometimes the  key,  key or  key gets accidentally pressed.

You had to send an email to your supervisor. Since you were in hurry, you didn’t even notice that the text was messed up. After you sent the email, you knew that you need some help.

Given the text you wrote, print the text your supervisor will receive.

Note: The  key changes the writing cursor's position to the beginning of the line, which means whatever after '<' goes before what is already written.

The  key changes the writing cursor's position to the end of the line, which means whatever after '>' goes after what is already written.

The  key removes the previous character to the current position. And if there is nothing written, nothing happens.

The   key enables the numbers on the keyboard if they were disabled previously, and vice-versa. Initially, the   is on, that is you can use the numbers.


string receivedText(string s) {
    // WRITE DOWN YOUR CODE HERE
    long long i,n=s.length(),x=1;
    string S="",S1="";
    stack<char>st,st1;
    for(i=0;i<n;i++)
    {
        if(s[i]=='<')
        {
            while(!st.empty())
            {
                st1.push(st.top());
                st.pop();
            }
           
        }
        else if(s[i]=='>')
        {
            while(!st1.empty())
            {
                st.push(st1.top());
                st1.pop();
            }
        }
        else if(s[i]=='*')
        {
            if(!st.empty())
                st.pop();  
        }
        else if(s[i]=='#')
        {
            x+=1;
        }
        else
        {
            if(s[i]>=48&&s[i]<=57)
            {
                if(x%2!=0)
                {
                    st.push(s[i]);
                }
            }
            else
            st.push(s[i]);
        }
    }
    while(!st1.empty())
    {
        st.push(st1.top());
        st1.pop();
    }
    while(!st.empty())
    {
        S+=st.top();
        st.pop();
    }
    reverse(S.begin(),S.end());
     
    return S;


}
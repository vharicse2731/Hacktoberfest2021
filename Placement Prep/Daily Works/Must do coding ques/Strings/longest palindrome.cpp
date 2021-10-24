
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0


USING DP WITH O(N^2) SPACE:

string solve(){
    string s;
    cin>>s;
    int n=s.size(),imin=1;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            imin=2;
        }
    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1];
                if(dp[i][j]==1){
                    imin=len;
                }
            }
        }
    }
    int j;
    for(int i=0;i<n-imin+1;i++){
        j=i+imin-1;
        if(dp[i][j]==1)
            return s.substr(i,j-i+1);
    }
    return "";
}


USING DP WITH O(1) SPACE:
https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/?ref=rp

/*
The idea is to generate all odd and even length palindromes and store the starting index and maxlength.

if two char matches .. it expands to next 2 characters by --low and ++high



Eg: gokkul
even:
go
ok
kk -> okku -> store (kk)
ku
ul

odd:
gok
okk
kku
kul


*/ 

for (int i = 1; i < len; ++i) { 
        // Find the longest even length palindrome 
        // with center points as i-1 and i. 
        low = i - 1; 
        high = i; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
  
        // Find the longest odd length 
        // palindrome with center point as i 
        low = i - 1; 
        high = i + 1; 
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
}
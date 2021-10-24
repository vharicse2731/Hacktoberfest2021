
// https://practice.geeksforgeeks.org/problems/longest-common-substring/0

/*
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

*/


int solve(){
    int m,n,maxi=0;
    cin>>m>>n;
    string s1,s2;
    cin>>s1>>s2;
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                maxi=max(maxi,dp[i][j]);
            }
            else
                dp[i][j]=0;
        }        
    }
    return maxi;
}
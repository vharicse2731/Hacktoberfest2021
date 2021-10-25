string findSubstring(string s, int k) {
    
    int n=s.size();
    if(k>n)
        return "Not found!";
    map<char,int>vow;
    vow['a']++;vow['e']++;vow['i']++;vow['o']++;vow['u']++;

    // vector<vector<int>>dp(n,vector<int>(n,0));

    // for(int i=0;i<n;i++){
    //     if(vow.find(s[i])!=vow.end())
    //         dp[i][i]=1;
    // }
    // for(int len=1;len<=k;len++){
    //     for(int i=0;i<n-len;i++){
    //         int j=i+len;
    //         dp[i][j]=dp[i][j-1]+dp[j][j];
    //     }
    // }
    // // for(int i=0;i<n;i++){
    // //     for(int j=0;j<n;j++){
    // //         cout<<dp[i][j]<<" ";
    // //     }
    // //     cout<<endl;
    // // }
    // int maxi=INT_MIN,ind=-1;
    // for(int i=0,j=k-1;j<n;i++,j++){
    //     if(dp[i][j]>maxi){
    //         maxi=dp[i][j];
    //         ind=i;
    //     }
    // }
    // if(maxi==0)
    //     return "Not found!";
    // string ans=s.substr(ind,k);
    // return ans;
    int ind=0,cur=0;
    for(int i=0;i<k;i++)
        if(vow.find(s[i])!=vow.end())
            cur++;
    int maxi=cur;
    for(int i=1;i<=n-k;i++){
        if(vow.find(s[i-1])!=vow.end())
            cur--;
        if(vow.find(s[i+k-1])!=vow.end())
            cur++;
        if(cur>maxi){
            maxi=cur;
            ind=i;
        }
    }
    if(maxi==0)
        return "Not found!";
    string ans=s.substr(ind,k);
    return ans;
}
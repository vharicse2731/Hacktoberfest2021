

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

/*

Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3
*/

int solve(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int maxi=0;
    for(auto a:dp)
        maxi=max(maxi,a);
    return maxi;
}
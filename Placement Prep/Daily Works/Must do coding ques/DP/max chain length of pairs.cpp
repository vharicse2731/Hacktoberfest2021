

// https://practice.geeksforgeeks.org/problems/max-length-chain/1
/*
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 
Output
3
1
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
the longest chain that can be formed is of length 3, and 
the chain is {{5, 24}, {27, 40}, {50, 90}}

(ii) The max length chain possible is only of length one.

*/

GREEDY :

const bool comp(struct val a,struct val b){
    return (a.second < b.second);
}
    
int maxChainLen(struct val p[],int n){
    sort(p,p+n,comp);
    int end=p[0].second,ans=1;
    for(int i=1;i<n;i++){
        if(p[i].first > end){
            end=p[i].second;
            ans++;
        }
    }
    return ans;
}


DP:

int maxChainLen(struct val p[],int n){
    sort(p,p+n,comp);
    int dp[n]={1};
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].first > p[j].second && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<dp[i])
            max=dp[i];
    }
    return max;
}
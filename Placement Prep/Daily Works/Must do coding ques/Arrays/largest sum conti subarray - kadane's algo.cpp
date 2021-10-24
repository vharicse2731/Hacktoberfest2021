
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

SIMPLE:

int solve(){
    int n,num;
    cin>>n;
    int cur=0,ans=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>num;
        cur+=num;
        if(cur>ans)
            ans=cur;
        if(cur<0)
            cur=0;
    }
    return ans;
}


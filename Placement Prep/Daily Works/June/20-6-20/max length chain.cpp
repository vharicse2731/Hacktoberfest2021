
// https://practice.geeksforgeeks.org/problems/max-length-chain/1/

/* You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
Your task is to complete the function maxChainLen which returns an integer denoting 
the longest chain which can be formed from a given set of pairs. */


bool logic(struct val s1,struct val s2){
    return s1.first<s2.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,logic);
    int len[n];
    for(int i=0;i<n;i++)
        len[i]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(p[i].second<p[j].first){
                len[i]=max(len[i],len[j]+1);
            }
        }
    }
    
    // for(int i=0;i<n;i++)
    //     cout<<len[i]<<" ";
    
    int max1=0;
    for(int i=0;i<n;i++){
        if(max1<len[i])
            max1=len[i];
    }
    return max1;
}
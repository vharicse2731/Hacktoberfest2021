
//https://practice.geeksforgeeks.org/problems/box-stacking/1
/*
Input:
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

Output
60
15
*/


bool compare(pii a,pii b){
    return (a.first.first * a.first.second)>(b.first.first * b.first.second);    
}

int maxHeight(int h[],int w[],int l[],int no)
{
    vector<pii> arr;
    for(int i=0;i<no;i++){
        if(h[i]>w[i])
            arr.push_back({{h[i],w[i]},l[i]});
        else
            arr.push_back({{w[i],h[i]},l[i]});
        if(w[i]>l[i])
            arr.push_back({{w[i],l[i]},h[i]});
        else
            arr.push_back({{l[i],w[i]},h[i]});
        if(l[i]>h[i])
            arr.push_back({{l[i],h[i]},w[i]});
        else
            arr.push_back({{h[i],l[i]},w[i]});
    }
    sort(arr.begin(),arr.end(),compare);
    int n=arr.size();
    int dp[n];
    
    for(int i=0;i<n;i++)
        dp[i]=arr[i].second;
        
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].first.first < arr[j].first.first && arr[i].first.second<arr[j].first.second && dp[i]<dp[j]+arr[i].second)
                dp[i]=dp[j]+arr[i].second;
        }
    }
    int maxi=dp[0];
    for(int i=1;i<n;i++)
        if(dp[i]>maxi)
            maxi=dp[i];
    return maxi;
}
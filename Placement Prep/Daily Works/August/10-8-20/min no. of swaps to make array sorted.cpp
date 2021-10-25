

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

// 4 3 2 1  ---> 2
// min no. of swaps to make array sorting 
// --> detect the total no. of cycles and sum up to ans.


int minSwaps(int arr[], int N){
    pair<int,int>ch[N];
    int count,ans=0;
    for(int i=0;i<N;i++){
        ch[i].first=arr[i];
        ch[i].second=i;
    }
        
    sort(ch,ch+N);
    
   // vector<bool>vis(N,false);
    bool vis[N]={false};
    for(int i=0;i<N;i++){
        if(vis[i] || i==ch[i].second)
            continue;
        int j=i;count=0;
        while(!vis[j]  ){
            vis[j]=true;
            count++;
            j=ch[j].second;
        }
        if(count>0)
            ans+=count-1;
    }
    
    return ans;
}
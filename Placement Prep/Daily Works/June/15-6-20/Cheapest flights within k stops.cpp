Problem:
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

Sol:
class Solution {
public:
    
/*    void findlen(int s,vector<vector<int>> arr,vector<bool> &vis,int dst,int k,int sum,int *val){
        //cout<<s<<" "<<k<<endl;
        if(k<0)
            return;
        vis[s]=true;
        if(s==dst && *val>sum){
            *val=sum;
            vis[s]=false;
            return;
        }
        
        for(int i=0;i<arr[0].size();i++){
            if(arr[s][i] && !vis[i])
                findlen(i,arr,vis,dst,k-1,sum+arr[s][i],val);
        }
        vis[s]=false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<bool>vis(n,false);
        vector<vector<int>>arr(n,vector<int>(n,0));
        
        for(int i=0;i<flights.size();i++){
            arr[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        
        // for(int i=0;i<flights.size();i++){
        //     for(int j=0;j<flights[0].size();j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=INT_MAX;
        findlen(src,arr,vis,dst,K+1,0,&ans);
        if(ans==INT_MAX)
            return -1;
        return ans;  */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int>cost(n,INT_MAX/2);
        cost[src]=0;
        
        for(int i=0;i<=K;i++){
            vector<int>dist(cost);
            for(auto cur : flights){
                dist[cur[1]]=min(dist[cur[1]],cost[cur[0]]+cur[2]);
            }
            cost=dist;
        }
        if(cost[dst]>=INT_MAX/2)
            return -1;
        return cost[dst];
    }
};


// min span tree - prims

// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<bool>vis(V,false);
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        if(!vis[a.second]){
            vis[a.second]=true;
            ans+=a.first;
            for(int b=0;b<graph[0].size();b++)
                if(graph[a.second][b]<INT_MAX && !vis[b])
                    pq.push(make_pair(graph[a.second][b],b));
        }
    }
    return ans;
}
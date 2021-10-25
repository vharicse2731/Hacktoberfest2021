
//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// nice method : https://ide.geeksforgeeks.org/ZBDjduGACH

optimal:

int find_set(int a) {
    while(arr[a]!=a) a=arr[a];
    return a;
}
bool make_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (arr[a] < arr[b])
            swap(a, b);
        arr[b] = a;
        return true;
    }
    else return false;
}

normal:

vector<int>par(1000);

int find(int x){
    while(x!=par[x]){
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void union1(int x,int y){
    int i=find(x);
    int j=find(y);
    par[i]=par[j];
}

int kruskal(int E, vector<vector<int>> &g,vector<pair<int,pair<int,int>>> &mp){
    int ans=0;
    sort(mp.begin(),mp.end());
    for(int i=0;i<E;i++){
        int x=mp[i].second.first;
        int y=mp[i].second.second;
        if(find(x)!=find(y)){
            ans+=mp[i].first;
            union1(x,y);
        }
    }
    return ans;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<pair<int,pair<int,int>>>mp;
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[0].size();j++){
            if(graph[i][j]!=INT_MAX){
                mp.push_back(make_pair(graph[i][j],make_pair(i,j)));
                graph[j][i]=INT_MAX;
            }
        }
    }
    
    for(int i=0;i<V;i++)
        par[i]=i;
        
    return kruskal(E,graph,mp);
}
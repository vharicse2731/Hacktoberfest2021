vector<int> stringAnagram(vector<string> d, vector<string> query) {
    int m=d.size();
    int n=query.size();

    map<string,int>mp;

    for(int i=0;i<m;i++){
        auto &it=d[i];
        sort(it.begin(),it.end());
        mp[it]++;
    }

    vector<int>ans(n,0);
    
    for(int i=0;i<n;i++){
        auto &it=query[i];
        sort(it.begin(),it.end());
        if(mp.find(it)!=mp.end())
            ans[i]=mp[it];
    }
    
    return ans;
}
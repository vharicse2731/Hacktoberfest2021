
// https://www.hackerrank.com/contests/hack-the-interview-v-asia-pacific/challenges/rerouting/submissions/code/1324524026

Your company has  servers. The information flows from one server to another through a connection.

If the information flows from server  to server , then . It's possible for some server , meaning information doesn't flow further.

You are given an array  consisting of  integers. You are tasked with making minimum number of changes to  array values so that the information from all servers can reach at exactly one server in the whole network, where it terminates.

If node  is terminal server, then .

vector<bool>gen;
void dfs(int i,vector<bool>&vis,vector<int>&arr,bool *notify){
    if(gen[i]){
        *notify=false;
        return;
    }
    gen[i]=true;
    vis[i]=true;
  //  if(s.count(i)){
  //      *notify=false;
  //      return;
  //  }
  //  s.insert(i);
        if(!vis[arr[i]]){
            dfs(arr[i],vis,arr,notify);
    }
}

int getMinConnectionChange(vector<int> connection) {
    connection.push_back(0);
    int ans=0;
    
    int n=connection.size();
    int flag=0;
    
    for(int i=n-1;i>0;i--)
        connection[i]=connection[i-1];
    
    for(int i=1;i<n;i++){
        if(i==connection[i])
            flag=1;
    }
    if(!flag)
        ans+=1;
    
  //  gen(n,0);
    
    
 //   map<int,int>mp;
    
    // for(int i=1;i<n;i++)
    //     mp[connection[i]]++;
    
   // set<int>s;
    
    vector<bool> vis(n,false);
    gen=vis;
    
    for(auto it:connection){
        // for(int i=0;i<n;i++)
        //     vis[i]=false;
        vector<bool> visi(n,false);
        bool noti=true;
        dfs(it,visi,connection,&noti);
        if(noti)
            ans+=1;
    }
    
    // for(int i=1;i<n;i++)
    //     cout<<i<<" "<<connection[i]<<endl;
    return ans-1;
}
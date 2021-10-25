https://leetcode.com/problems/unique-paths/


class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        if(og[0][0]==1 || og[og.size()-1][og[0].size()-1]==1)
            return 0;
        int dp[og.size()][og[0].size()];
        dp[0][0]=1;
        for(int i=1;i<og.size();i++){
            if(og[i][0]==1)
                dp[i][0]=0;
            else
                dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<og[0].size();i++){
            if(og[0][i]==1)
                dp[0][i]=0;
            else
                dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<og.size();i++){
            for(int j=1;j<og[0].size();j++){
                    if(og[i-1][j]!=1 && og[i][j-1]!=1 )
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    else if(og[i-1][j]!=1)
                        dp[i][j]=dp[i-1][j];
                    else if(og[i][j-1]!=1)
                        dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=0;
                }
            }
        
        return dp[og.size()-1][og[0].size()-1];
    }
};


// https://leetcode.com/problems/unique-paths-iii/


class Solution {
public:
    
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int ans=0;
    
    bool issafe(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    void dfs(vector<vector<int>> arr,int i,int j,int curz,int totz){
        
        if(arr[i][j]==2 && curz==totz+1){
            ans++;
            return;
        }
        if(arr[i][j]==2)
            return;
        arr[i][j]=-1;
        for(int k=0;k<4;k++){
            if(issafe(i+x[k],j+y[k],arr.size(),arr[0].size()) && arr[i+x[k]][j+y[k]]!=-1){
                dfs(arr,i+x[k],j+y[k],curz+1,totz);
            }
        }
        arr[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int srci,srcj,desti,destj,count=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    srci=i;
                    srcj=j;
                }
                if(grid[i][j]==2){
                    desti=i;
                    destj=j;
                }
                if(grid[i][j]==0)
                    count++;
            }
        }
        dfs(grid,srci,srcj,0,count);
        return ans;
  /*   //   int dp[(desti-srci)+1][(destj-srcj)+1];
        
        dp[0][0]=1;
        
        for(int i=1;i<=desti-srci;i++){
            if(grid[i+srci][srcj]==-1)
                dp[i][0]=0;
            else
                dp[i][0]=dp[i-1][0];
        }
        
        for(int i=1;i<=destj-srcj;i++){
            if(grid[srci][i+srcj]==-1)
                dp[0][i]=0;
            else
                dp[0][i]=dp[0][i-1];
        }
        
        for(int i=1;i<=desti-srci;i++){
            for(int j=1;j<=destj-srcj;j++){
                if(grid[i+srci][j+srcj]==-1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        } 
        
        
        for(int i=0;i<=desti-srci;i++){
            for(int j=0;j<=destj-srcj;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[desti-srci][destj-srcj];   */
    }
};
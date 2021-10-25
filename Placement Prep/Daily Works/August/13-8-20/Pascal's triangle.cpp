
// https://leetcode.com/problems/pascals-triangle-ii/

/*
				1					-> 0  <-- n
			1		1				-> 1
		1 		2		1			-> 2
	1		3		3 		1		-> 3
1		4		6		4		1	-> 4
*/


DP:

    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>>dp(rowIndex+1);
        dp[0].resize(1);
        dp[0][0]=1;
        
        for(int i=1;i<rowIndex+1;i++){
            dp[i].resize(i+1);
            dp[i][0]=1;
            dp[i][i]=1;
            
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[rowIndex];
    }
	
RECURSION:

vector<int> helper(int n){
        if(n<=0)
            return {};
        if(n==1)
            return {1};
        if(n==2)
            return {1,1};
        vector<int> prev=helper(n-1);
        vector<int>ans(n,1);
        for(int i=1;i<n-1;i++){
            ans[i]=prev[i-1]+prev[i];
        }
        return ans;
}
vector<int> getRow(int n) {
    return helper(n+1);
}	
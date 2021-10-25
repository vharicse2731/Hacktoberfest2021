
https://leetcode.com/problems/unique-binary-search-trees/


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;dp[1]=1;                // base condition
        for(int i=2;i<=n;i++){          // traversing through n nodes
            for(int j=1;j<=i;j++){      // setting root node
                dp[i]+=dp[j-1]*dp[i-j]; // nodes in left * nodes in right for every root node
            }
        }
        return dp[n];
    }
};
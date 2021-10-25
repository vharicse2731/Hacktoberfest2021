

https://leetcode.com/problems/coin-change/

You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0)
            return 0;
        vector<int>dp(amount+1,INT_MAX/2);
        dp[0]=0;
        for(auto it:coins){
            for(int i=it;i<=amount;i++){
                dp[i]=min(dp[i],1+dp[i-it]);
            }
        }
        if(dp[amount]>=INT_MAX/2)
            return -1;
        return dp[amount];
    }
};




https://leetcode.com/problems/coin-change-2/

You are given coins of different denominations and a total amount of money.
 Write a function to compute the number of combinations that make up that amount. 
 You may assume that you have infinite number of each kind of coin.
 
 class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(auto it : coins){
            for(int i= it ;i<=amount;i++){
                if(i<=amount)
                    dp[i]+=dp[i-it];
            }
        }
        return dp[amount];
    }
};
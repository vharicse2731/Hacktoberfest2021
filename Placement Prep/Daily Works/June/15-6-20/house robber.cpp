// https://leetcode.com/problems/house-robber/submissions/

set 1: row

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];

        
            int dp[nums.size()];
            memset(dp,0,sizeof(dp));
            dp[0]=nums[0];
            dp[1]=max(nums[0],nums[1]);
         //   cout<<dp[0]<<" "<<dp[1]<<endl;
            for(int i=2;i<nums.size();i++){
                dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
            }
            return dp[nums.size()-1];
        
    }
};

set 2: circle
//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
      //  int n=nums.size();
        int maxi=INT_MIN;
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
            
        int dp[nums.size()];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size()-1;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        maxi=dp[nums.size()-2];
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<nums.size();i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        return max(maxi,dp[nums.size()-1]);
        
    }
};
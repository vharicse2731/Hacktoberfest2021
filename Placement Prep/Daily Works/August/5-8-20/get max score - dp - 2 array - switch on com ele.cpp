
/*
2 4 5 8 10
4 6 8 9

valid path with greatest sum : 2 4 6 8 10

We can switch over the arrays only on common elements
*/

// https://leetcode.com/problems/get-the-maximum-score/

class Solution {
public:
    int mod = 1000000007;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1,j=nums2.size()-1;long long sum1=0,sum2=0,ans=0;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j])
                sum1+=nums1[i--];
            else if(nums1[i]<nums2[j])
                sum2+=nums2[j--];
            else{
                ans=max(sum1,sum2)+nums1[i];
                sum1=ans;
                sum2=ans;
                i--;j--;
            }
        }
        while(i>=0){
            sum1+=nums1[i--];
        }
        while(j>=0){
            sum2+=nums2[j--];
        }
        ans=(max(sum1,sum2))%mod;
        return (int)ans;
    }
};
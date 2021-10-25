/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.


I/p:
array  A

1<=A[i]<=N

*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int a:nums){
            int ind=abs(a)-1;
            if(nums[ind]<0)
                ans.push_back(ind+1);
            else
                nums[ind]*=-1;
        }
        return ans;        
    }
};
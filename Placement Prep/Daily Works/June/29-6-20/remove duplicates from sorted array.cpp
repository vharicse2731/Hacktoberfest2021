
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

Mine:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[i]==nums[j])
                j++;
            else{  
                i++;
                nums[i]=nums[j];
                j++;
            }
        }
 //       cout<<i;
        return i+1;
    }
};

optimal:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int idx = 1; idx < nums.size(); idx++)
        {
            if (nums[idx - 1] == nums[idx])
            {
                count++;
            }
            else
            {
                nums[idx - count] = nums[idx];
            }
        }
        return nums.size() - count;
    }
};
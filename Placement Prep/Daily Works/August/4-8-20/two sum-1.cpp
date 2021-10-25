

// two sum
/*
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.


Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++)
        //         if(nums[i]+nums[j]==target)
        //             return {i,j};
        // }
        // return {0,0};
        map<int,int>mp;int se,ind;
        for(int i=0;i<nums.size();i++){
            se=target-nums[i];
            auto it=mp.find(se);
            if(it!=mp.end() && it->second!=i)
                return {i,it->second};
            mp[nums[i]]=i;
        }
        return {0,0};
    }
};


OPTIMAL:
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.count(target-nums[i])) {
                return {m[target-nums[i]],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
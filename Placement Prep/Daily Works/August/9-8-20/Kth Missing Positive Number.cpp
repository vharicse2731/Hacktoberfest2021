
// https://leetcode.com/problems/kth-missing-positive-number/

/*
array in strictly increasing order
ARR: 2,3,4,7,11
K:5
-->9
*/


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int orig=0;
        for(int i=0;i<arr.size();i++){
            orig++;
            if(arr[i]!=orig){
                k--;
                i--;
            }
            
            if(k==0)
                return orig;
        }
        while(k){
            orig++;
            k--;
        }
        return orig;
    }
};
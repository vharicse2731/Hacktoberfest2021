

// count good triplets
// https://leetcode.com/contest/weekly-contest-200/problems/count-good-triplets/


class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j])<=a){
                    for(int k=j+1;k<n;k++){
                        if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c )
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
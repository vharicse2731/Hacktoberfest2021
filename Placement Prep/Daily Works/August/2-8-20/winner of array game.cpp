
// array winner
// https://leetcode.com/contest/weekly-contest-200/problems/find-the-winner-of-an-array-game/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cmin=0,cur,j,maxi=INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            cur=arr[i];cmin=0;
            maxi=max(maxi,cur);
            j=i+1;
            if(i-1>=0 && arr[i-1]<arr[i]){
                cmin++;}
            while(cmin!=k && j<arr.size()){
                if(arr[j++]<=cur){
                    cmin++;}
                else
                    break;
            }
            if(cmin==k){
                return cur;}
        }  
        return maxi;
    }
};
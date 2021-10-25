

//https://leetcode.com/problems/next-permutation/

INBUILT:
next_permutation(nums.begin(), nums.end());

MINE:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2,j=n-1;
        while(i>=0){ 
            if(nums[i]<nums[i+1]) break;
            i--;
        }
        if(i>=0){
            while(j>=0){
                if(nums[j]>nums[i]) break;
                j--;
            }   
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};


OPTIMAL:

// class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=int(arr.size());
        int st,ed=n-1,st2;
      for(st=ed-1;st>=0;st--)
      {
          if(arr[st]<arr[st+1])
          {
              break;
          }
      }
      if(st==-1)
      {
          sort(arr.begin(),arr.begin()+n);
           {
        for(auto i : arr)
            cout << i << " ";
        cout << endl;
    }
          return;
      }
      int i=st+1,j=ed;
      while(i<j)
      {
          swap(arr[i],arr[j]);
          i++;
          j--;
      }
 
      st2 = upper_bound(arr.begin()+st,arr.begin()+ed+1,arr[st]) - arr.begin();
      swap(arr[st],arr[st2]);
       {
        for(auto i : arr)
            cout << i << " ";
        cout << endl;
    }
        return;
    }
};
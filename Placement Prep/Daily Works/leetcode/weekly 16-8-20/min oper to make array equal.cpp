


//https://leetcode.com/contest/weekly-contest-202/problems/minimum-operations-to-make-array-equal/


/*

You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e. 0 <= i < n).

In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] 
(i.e. perform arr[x] -=1 and arr[y] += 1). 
The goal is to make all the elements of the array equal. 
It is guaranteed that all the elements of the array can be made equal using some operations.

Given an integer n, the length of the array. Return the minimum number of operations needed to make all the elements of arr equal.

*/

int minOperations(int n) {
        if(n==1)
            return 0;
        int t=n-1;
        int a=t*2+1,ans=0;
        while(a>n){
            ans+=(a-n);
            t--;
            a=t*2+1;
        }
        return ans;
    }
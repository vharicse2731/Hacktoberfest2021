

// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

/*
INPUT : N K

EX:
Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

*/

    vector<int>ans;
    void helper(int cur,int n,int k){
        if(n==1){
            ans.push_back(cur);return;
        }
        if((cur%10)+k <10) helper(cur*10+(cur%10)+k,n-1,k);
        if(k && (cur%10)-k >=0) helper(cur*10+(cur%10)-k,n-1,k);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1) return {0,1,2,3,4,5,6,7,8,9};
        ans.clear();
        for(int i=1;i<10;i++)
            helper(i,N,K);   
    return ans;
    }
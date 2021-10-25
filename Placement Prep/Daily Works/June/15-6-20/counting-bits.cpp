
// https://leetcode.com/problems/counting-bits/submissions/


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res(num+1,0);
        if(num==0)
            return res;
        res[1]=1;
        if(num==1)
            return res;
        res[2]=1;
        if(num==2)
            return res;
        for(int i=3;i<=num;i++){
            if(i%2==0)
                res[i]=res[i/2];
            else
                res[i]=res[i/2]+1;
        }
        return res;
    }
};
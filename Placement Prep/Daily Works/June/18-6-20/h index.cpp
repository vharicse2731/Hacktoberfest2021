
//  https://leetcode.com/problems/h-index/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
   //     sort(citations.begin(),citations.end(),greater<>());
        for(int i=0;i<citations.size();i++){
            if(citations[i] >= citations.size()-i)
                return citations.size()-i;
        }
        return 0;
    }
};
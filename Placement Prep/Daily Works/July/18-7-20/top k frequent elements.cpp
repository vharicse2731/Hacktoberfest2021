
// https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int>mp;
        vector<int>ans;
        for(int a:nums) mp[a]++;
        priority_queue<pair<int,int>>pq;
        for(auto a:mp)  pq.push(make_pair(a.second,a.first));
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
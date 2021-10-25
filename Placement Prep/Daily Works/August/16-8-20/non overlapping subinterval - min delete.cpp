

// https://leetcode.com/problems/non-overlapping-intervals/

/*


*/

GREEDY:

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        sort(intervals.begin(),intervals.end(),[](auto l,auto r){return l[0]<=r[0];});
        int r=intervals[0][1];int ans=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=r){
                ans++;
                r=intervals[i][1];
            }
            else{
                r=min(r,intervals[i][1]);
            }
        }
        return n-ans;
    }
	
	
DP:

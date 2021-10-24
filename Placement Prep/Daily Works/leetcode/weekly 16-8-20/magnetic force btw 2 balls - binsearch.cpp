


// https://leetcode.com/contest/weekly-contest-202/problems/magnetic-force-between-two-balls/

/*

In universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. 
The minimum magnetic force is 3. 
We cannot achieve a larger minimum magnetic force than 3.

*/

bool dist(vector<int>pos,int mid,int n,int m){
        int a=pos[0],count=1;
        for(int i=1;i<n;i++){
            if(pos[i]-a >=mid){
                count++;
                a=pos[i];
            }
            if(count>=m)
                return 1;
        }
        return 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=0,n=position.size(),mid;
        int h=position[n-1];
        int ans;
        while(l<=h){
            mid=l+(h-l)/2;
            if(dist(position,mid,n,m)){
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
    }
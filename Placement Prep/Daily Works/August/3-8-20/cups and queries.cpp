



// Cups and queries;
/*

There are n cups in a row (assume 1-based indexing for the cups). 
You have n balls and you place i'th ball in the cup balls(i) such that there's atmost 1 ball in each of the cups, 
therefore the elements of balls are pairwise distinct.


Now, you perform s swaps, each swap contains two integers x and y, 
you are required to swap the positions of cups at index x and index y.

Finally, you are asked q queries, each query contains two space separated integers l and r, 
you need to answer the total number of balls 
that are present in the cups having index from l to r (both inclusive).

Eg. n=4,m=2,balls={2,4}, s=3

{2,4}
{2,1}
{2,3}

finally balls are in {1,4}

que: l=2, r=4

ans= 1;



sam i/p:
3 2 2 2
1 3
1 3
3 2
1 2
3 3

o/p:
2 0

sample i/p:
3 1 3 2
2
1 2
1 3
3 1
1 2
1 3

o/p
1 1
*/

// https://www.hackerrank.com/contests/hack-the-interview-vi-asia-pacific/challenges


int bin(vector<int> &arr,int l,int r,int k){
    int ind=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k){
            ind=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ind;
}
vector<int> countCups(int n, vector<int> balls, vector<vector<int>> swaps, vector<vector<int>> queries) {
    map<int,bool>mp;    
    for(auto a:balls)
        mp[a]=1;
        
    int l,r;
    for(int i=0;i<swaps.size();i++){
        l=swaps[i][0];
        r=swaps[i][1];
        
        if((mp[l] && mp[r])||(!mp[l] && !mp[r])) continue;
        if(mp[l] && !mp[r]){
            mp[r]=1;
            mp.erase(l);
        }
        else if(mp[r] && !mp[l]){
            mp[l]=1;
            mp.erase(r);
        }
    }
    // maxi=(--mp.end())->first;

    vector<int>arr(balls.size());
    l=0;
    for(auto a:mp)
        if(a.second)
            arr[l++]=a.first;
        
    vector<int>ans;
    
    for(auto a:queries){
        l=bin(arr,0,balls.size()-1,a[0]);
        r=bin(arr,0,balls.size()-1,a[1]);
   //     cout<<l<<" "<<r<<endl;
        if(arr[r]<a[0]){
            ans.push_back(0);
        }
        else{
            if(arr[l]<a[0]){
                l++;
            }
            ans.push_back(r-l+1);
        }
    }
    return ans;
}

USING LOWER BOUND:

for(auto a:queries){
        if(a[0]>maxi){
            ans.push_back(0);continue;
        }
        if(a[1]<arr[0]){
            ans.push_back(0);continue;
        }
        l=lower_bound(arr.begin(),arr.end(),a[0])-arr.begin();
        r=lower_bound(arr.begin(),arr.end(),a[1])-arr.begin();
        if(arr[r]!=a[1])
            r--;
        ans.push_back(r-l+1);
    }
    return ans;
}
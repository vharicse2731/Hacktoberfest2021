

/*

There is a street in Lucknow which is famous for its street market. 
The street starts at point 0 and extends upto 10^9 units 
(you can think of these points on a 1-D line starting at zero and extending to the right upto 10^9).

At a moment there are several customers and several street vendors on the street. 
Each customer in the street wants to reach a vendor as soon as possible. 
Can you tell for each customer how far is the nearest vendor and in which direction, 
so that he/she can move to the correct position as desired.

Note: If a customer has nearest vendors at equal distance on both sides. 
Then the customer prefers to move left

I/P:

N
N int of cust pos.
M
m intergers of vend pos.


sam I/p:
2
1 3
2
0 3

samp O/p:
1 L
0 O

samp I/p:
1
4
2
2 6 

samp o/p:
2 L


*/

// https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-01-august/challenges/markets/problem


#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m;
    
    cin>>n;
    vector<int>cus(n);
    for(int &a:cus)
        cin>>a;
    
    cin>>m;
    vector<int>ven(m);
    for(int &a:ven)
        cin>>a;
    
    sort(ven.begin(),ven.end());
    
    vector<pair<int,char>>ans;
    
    int li,ri,lv,rv;
    for(auto a : cus){
        lv=INT_MAX;rv=INT_MAX;
        ri=lower_bound(ven.begin(),ven.end(),a)-ven.begin();
        li=ri-1;
        rv=abs(ven[ri]-a);
        if(li>=0)
            lv=abs(ven[li]-a);
        if(rv == 0)
            ans.push_back({0,'O'});
        else if(lv<=rv)
            ans.push_back({lv,'L'});
        else
            ans.push_back({rv,'R'});
    }
    
    for(auto a:ans)
        cout<<a.first<<" "<<a.second<<endl;
    
    return 0;
}
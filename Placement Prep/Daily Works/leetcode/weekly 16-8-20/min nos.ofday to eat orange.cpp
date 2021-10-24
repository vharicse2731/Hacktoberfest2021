

//https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

/*
n-(n/2)=n/2;
n-(2*n/3) = n/3;
*/

QUEUE:

int minDays(int n) {
        queue<int>q;
        map<int,int>mp;
        q.push(n);
        mp[n]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
         //   cout<<a<<" ";
            if(a==0){
                return mp[a];
            }
            if(a%3==0 && !mp[a-(2*(a/3))]){
                mp[a-(2*(a/3))]=mp[a]+1;
                q.push(a-(2*(a/3)));
            }
            if(a%2==0 && !mp[a-(a/2)]){
                mp[a-(a/2)]=mp[a]+1;
                q.push(a/2);
            }
            if(!mp[a-1] && !mp[a-1]){
                mp[a-1]=mp[a]+1;
                q.push(a-1);
            }
            
        }
        return 0;
    }
	
	
DP:
    unordered_map<int, int> seen;
    int minDays(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(seen.find(n) != seen.end()){
            return seen[n];
        }
        int ans = min(minDays(n/2) + n % 2 + 1, minDays(n/3) + n % 3 + 1);
        return seen[n] = ans;
    }
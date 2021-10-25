
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

SPACE : O(N)

int maxProfit(vector<int>& p) {
        int n=p.size();
        if(n<=1)
            return 0;
        int left[n],right[n];
        left[0]=INT_MIN;right[n-1]=INT_MIN;
        int mini=p[0],maxi=p[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],p[i]-mini);
            mini=min(mini,p[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],maxi-p[i]);
            maxi=max(maxi,p[i]);
        }
        int ans=max(0,left[n-1]);
        for(int i=1;i<n-2;i++){
            ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
}


SPACE : O(1)

int maxProfit(vector<int>& prices) {
        if(prices.size()==0){return 0;}
        int buy1=INT_MIN, sell1=INT_MIN, buy2=INT_MIN, sell2=INT_MIN;
		for(auto p: prices){
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1+p);
            buy2=max(buy2, sell1-p);
            sell2=max(sell2, buy2+p);
        }
      return sell2;  
}
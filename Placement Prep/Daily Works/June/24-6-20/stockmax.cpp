


https://www.hackerrank.com/contests/acm-placement-dp/challenges/stockmax


Efficient sol.:
long stockmax(vector<int> prices) {
	int temp=INT_MIN;long pro=0;
	for(int i=prices.size()-1;i>=0;i--){
		if(temp<prices[i]){
			temp=prices[i];
		}
		pro+=temp-prices[i];
	}
	return pro;
}


My sol:

long stockmax(vector<int> prices) {
//     vector<int>ans(n,0);
//     for(int i=;i<prices.size();i++){
//         for(int j=0;j<i;j++){
//             if(prices[j]<prices[i]){
//                 dp[i]=dp[i]+prices[i]=prices[j];
//             }
//         }
        
//     }
    priority_queue<pair<int,int>>pq;
    for(long unsigned int i=0;i<prices.size();i++){
        pq.push(make_pair(prices[i],i));
    }
    // while(!pq.empty()){
    //     auto it=pq.top();
    //     pq.pop();
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    
    long int profit=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int temp=it.second;
        for(int i=temp-1;i>=0;i--){
            if(prices[i]==INT_MAX)
                break;
            if(prices[i]<it.first){
                profit+=it.first-prices[i];
                prices[i]=INT_MAX;
            }
        }
    }
    return profit;
}
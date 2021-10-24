
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

GREEEDY (for Pos. no.)
pair<int,int> solve(){
    int n,sum,cur=0,ind;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0,j=0;
    while(i<n){
        if(cur==sum)
            return {j,i-1};
        else if(cur<sum)
            cur+=arr[i++];
        else
            cur-=arr[j++];
    }
    while(cur>=sum){
        if(cur==sum)
            return {j,i-1};
        cur-=arr[j++];
    }
	return {-1,-1};
}


Alt for NAIVE:

for(int j=0;j<N;j++)
	    {
	        sum=sum+A[j];
	        while(sum>S)
	        {
	            sum=sum-A[pivot];
	            pivot++;
	        }
	        if(sum==S)
	        {
	            cout<<pivot+1<<" "<<j+1<<"\n";
	            flag=1;
	            break;
	        }
	    }

NAIVE:

  int sum;
    for(int i=0;i<n;i++){
        sum=arr[i];
        for(int j=i+1;j<n;j++){
            sum+=arr[j];
            if(sum==s)
                return {i,j};
        }
    }
    return {-1,-1};
}


DP:
// handling -ve nos.

unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cur+=arr[i];
        if(cur==sum){
            return {0,i};
        }
        if(mp.find(cur-sum)!=mp.end()){
            return {mp[cur-sum]+1,i};
        }
        mp[cur]=i;
    }
    return {-1,-1};
	

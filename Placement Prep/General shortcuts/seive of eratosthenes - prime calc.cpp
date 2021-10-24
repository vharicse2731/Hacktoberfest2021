
// https://www.geeksforgeeks.org/sieve-of-eratosthenes/


bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
	
	
	
	FOR PRINTING :
	
	void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1,true);
    for(int i=2;i<=n;i++){
        if(arr[i]){
            cout<<i<<" ";
            for(int j=i*i;j<=n;j=j+i)
                arr[j]=false;
        }
    }
}


//https://practice.geeksforgeeks.org/problems/count-the-triplets/0

COMP : N^2 logn

void solve(){
    int n;
    cin>>n;
    int arr[n];
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s.find(arr[i]+arr[j])!=s.end())
                ans++;
        }
    }
    cout<<((ans==0)?-1:ans)<<endl;
}

COMP: N^2 (Distinct integers --> cant handle duplicates)

void solve(){
    int n,ans=0;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);  
    int i=n-1,j,k,sum;
    
    for(i;i>1;i--){
        k=0;j=i-1;
        while(k<j){
            sum=arr[j]+arr[k];
            if(sum==arr[i]){
                ans++;
                k++;
                j--;
            }
            else if(sum<arr[i])
                k++;
            else
                j--;
        }
    }
        
    cout<<((ans==0)?-1:ans)<<endl;
}


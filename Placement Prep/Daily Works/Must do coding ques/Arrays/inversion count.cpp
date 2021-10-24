
//https://practice.geeksforgeeks.org/problems/inversion-of-array/0/
/*
nversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. 
If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
1
5
2 4 1 3 5

Output:
3

*/

ONE METHOD:

long long int merge(long long int arr[],int l,int mid,int r){
    long long int c=0;
    long long int i=l,j=mid,k=0;
    long long int temp[r-l+1];
    while(i<mid && j<=r){
        if(arr[i]>arr[j]){
            c+=mid-i;
            temp[k++]=arr[j++];
        }
        else
            temp[k++]=arr[i++];
    }
    while(i<mid)
        temp[k++]=arr[i++];
    while(j<=r)
        temp[k++]=arr[j++];
    k=0;
    for(int i=l;i<=r;i++){
        arr[i]=temp[k++];
    }
    return c;
}

long long int inv(long long int arr[],int l,int r){
    if(l>=r)
        return 0;
    long long int c=0;
    long long int mid=l+(r-l)/2;
    c+=inv(arr,l,mid);
    c+=inv(arr,mid+1,r);
    c+=merge(arr,l,mid+1,r);
    return c;
}

long long int solve(){
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return inv(arr,0,n-1);
}

USING O(N) SPACE:

long int merge(vector<int> &arr,vector<int> &temp,int l,int mid,int h){
    int i=l,j=mid,k=l; long int inv=0;
    while(i<mid && j<=h){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv+=mid-i;
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=h){
        temp[k++]=arr[j++];
    }
    for(int i=l;i<=h;i++)
        arr[i]=temp[i];
    return inv;
}

long int mergesort(vector<int> &arr,vector<int> &temp,int l,int h){
    long int inv=0;int mid;
    if(l<h){
        mid=l+(h-l)/2;
        inv+=mergesort(arr,temp,l,mid);
        inv+=mergesort(arr,temp,mid+1,h);
        inv+=merge(arr,temp,l,mid+1,h);
    }
    return inv;
}


// https://practice.geeksforgeeks.org/problems/equilibrium-point/0

/*

Given an array A of N positive numbers. 
The task is to find the position where equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements 
before it is equal to the sum of elements after it.


2
1
1
5
1 3 5 2 2

Output:
1
3
*/

int solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0,j=n-1;
    int s1=0,s2=0;
    while(i<=j-1){
        if(s1<s2)
            s1+=arr[i++];
        else if(s1>s2)
            s2+=arr[j--];
        else{
            s1+=arr[i++];
            s2+=arr[j--];
        }
    }
    if(i==j && s1==s2)
        return i+1;
    return -1;
}
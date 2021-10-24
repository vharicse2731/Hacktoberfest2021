
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0/


/*

Input:
2
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Output:
0 1 2 3 5 6 7 8 9
5 10 12 18 20

*/

void solve(){
    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0;i<n;i++)
        cin>>a1[i];
    for(int i=0;i<m;i++)
        cin>>a2[i];
    int i=0,j=0,k=n;
    while(i<k && j<m){
        if(a1[i]<=a2[j])
            i++;
        else{
            swap(a2[j++],a1[--k]);
        }
    }
    sort(a1,a1+n);
    sort(a2,a2+m);
    for(int i=0;i<n;i++)
        cout<<a1[i]<<" ";
    for(int i=0;i<m;i++)
        cout<<a2[i]<<" ";
    cout<<endl;
}
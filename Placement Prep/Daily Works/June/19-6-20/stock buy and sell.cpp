

https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

void stockBuySell(int price[], int n) {
    // code here
    int i=0,ch,flag=0;
    while(i<n){
        if(i+1 < n && price[i] == price[i+1]){
            i++;
            continue;
        }
        if(i+1 < n && price[i]<price[i+1])
            cout<<"("<<i<<" ";
        ch=0;
        while(i+1<n && price[i]<=price[i+1]){
            i++;ch=1;flag=1;
        }
        if(ch==1)
            cout<<i<<") ";
        i++;
    }
    if(flag==0)
        cout<<"No Profit";
    cout<<endl;
}
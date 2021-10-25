

/*

Given int N --> permuatation : 1 2 3 ... N-1 N
given int M --> M operations : 
M int follows... int num

o/p:
for every operation return sum by doing operations.

if num present in N , swap first and last element.
if NOt present, pop last element and insert the new one (num).


*/

// https://www.hackerrank.com/contests/hack-the-interview-vi-asia-pacific/challenges



#include<bits/stdc++.h>
using namespace std;
vector<bool>arr(500001);


vector<long> pe(int N, vector<int> op) {
    
    vector<long>ans;
    
    for(int i=N+1;i<=500000;i++)
        arr[i]=false;
    
    for(int i=1;i<=N;i++)
        arr[i]=true;

    long int sum=0;
    
    for(int k=1;k<=N;k++)
        sum+=k;
    
    int last=N,j,first=1;
    
    for(int i=0;i<(int)op.size();i++){
        j=op[i];
        if(arr[j]){
            swap(first,last);
        }
        else{
            sum=sum-last+j;
            arr[last]=false;
            last=j;
            arr[last]=true;
        }
        ans.push_back(sum);
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>op(m);
    for(int &a:op)
        cin>>a;
    vector<long>ans=pe(n,op);
    for(auto a:ans){
        cout<<a<<endl;
    }
    return 0;
}
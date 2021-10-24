
// https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-08-aug/challenges/arrange-as-said/problem

#include<bits/stdc++.h>
using namespace std;
string pat;
int arr[26];

static bool comp(string a,string b){
    int i=0,j=0;
    int m=a.size(),n=b.size();
    if(m==0)
        return true;
    if(n==0)
        return false;
    while(i<m && j<n){
        if(arr[a[i]-'a']<arr[b[j]-'a'])
            return true;
        else if(arr[a[i]-'a']>arr[b[j]-'a'])
            return false;
        else{
            i++;j++;
        }        
    }
    if(i<m)   
        return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s.begin(),s.end(),comp);
    for(auto x:s)
        cout<<x<<endl;
}

int main() {
    pat.clear();
    cin>>pat;
    for(int i=0;i<26;i++){
        arr[pat[i]-'a']=i;
    }
    solve();
    return 0;
}

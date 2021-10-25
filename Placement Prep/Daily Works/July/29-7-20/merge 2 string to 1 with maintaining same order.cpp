
// https://www.spoj.com/problems/ADFRUITS/

//  Merge 2 string to single ,so to carry the order in it.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	string s2;
	char s1[101];
	while(scanf("%s",s1)!=EOF){
	    cin>>s2;
	    int n=strlen(s1),m=s2.size();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s1[i-1]==s2[j-1])
	                dp[i][j]=dp[i-1][j-1]+1;
	            else
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }

	    vector<char>lcs;
	    int i=n,j=m;
	    while(i>0 && j>0){
	        if(s1[i-1]==s2[j-1]){
	            lcs.insert(lcs.begin(),s1[i-1]);
	            i--;j--;
	        }
	        else if(dp[i-1][j] > dp[i][j-1])
	            i--;
	        else
	            j--;
	    }
	    vector<char>ans;
	    i=0;j=0;int k=0;
	    while(k<lcs.size()){
	        while(s1[i] != lcs[k]){
	            ans.push_back(s1[i]);i++;
	        }
	        while(s2[j] != lcs[k]){
	            ans.push_back(s2[j]);j++;
	        }
	        ans.push_back(lcs[k]);
	        k++;
	        i++;
	        j++;
	    }
	    while(i<n){
	        ans.push_back(s1[i++]);
	    }
	    while(j<m){
	        ans.push_back(s2[j++]);
	    }
	    for(char a:ans)
	        cout<<a;
	    cout<<endl;
	}
	return 0;
}
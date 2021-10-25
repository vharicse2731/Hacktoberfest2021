#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	string s;
	while(1){
	cin>>s;
	if(s=="0")
		break;
	vector<long long int>dp(s.size()+1,0);
	dp[0]=1;
	if(s[0]!='0')
		dp[1]=1;
	else
		dp[1]=0;
		
	for(long long int i=2;i<=s.size();i++){
		if(s[i-1]!='0')
			dp[i]=dp[i-1];
		if(s[i-2]!='0' && (10*(s[i-2]-'0')+(s[i-1]-'0'))<=26 )
			dp[i]+=dp[i-2];
	}
	cout<<dp[s.size()]<<endl;
	dp.clear();
	}
	return 0;
}
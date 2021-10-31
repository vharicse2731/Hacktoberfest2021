
#include <bits/stdc++.h>
using namespace std;

int countNonEmptySubstr(string str)
{
int n = str.length();
return n*(n+1)/2;
}

// driver code
int main()
{
	string s = "abcde";
	cout << countNonEmptySubstr(s);
	return 0;
}

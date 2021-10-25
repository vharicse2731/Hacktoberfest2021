https://leetcode.com/problems/palindromic-substrings/

Approach 1 : TLE
public:
    bool ispal(string str){
        string s1=str;
        reverse(s1.begin(),s1.end());
        return s1==str;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(s[i]==s[j] && ispal(s.substr(i,j-i+1))){
                    count++;
                }
            }
        }
        return count;
    }


Approach 2 : DP
class Solution {

    int countSubstrings(string s) {
        
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len =2 ;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(len==2){
                    dp[i][j]= s[i]==s[j];//if(dp[i][j]) count++;
                }
                else{
                    dp[i][j]= (s[i]==s[j]) && dp[i+1][j-1];//if(dp[i][j]) count++;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==true)
                    count++;
            }
        }
        return count;
    }
};


Approach 3 : Sol. (expand by centre)
class Solution {
    public int countSubstrings(String S) {
        int N = S.length(), ans = 0;
        for (int center = 0; center <= 2*N-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && S.charAt(left) == S.charAt(right)) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
}
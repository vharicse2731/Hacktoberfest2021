
//  https://leetcode.com/problems/remove-k-digits/



class Solution {
    /*
    k=3;
        1 4 3 2 2 1 9
      0 0 0 0 0 0 0 0
    1 0 0 4 4 4 4 4 4
    2 0 0 0 3 3 3 3 3
    3 0 0 0 0 2 2 2 2
        
    */
public:
    string removeKdigits(string num, int k) {
        string ans="";
        if(num.size()==0)
            return num;
        if(num.size()==k)
            return "0";
        ans+=num[0];
        int i=1;
        while(i< num.size() ){
            while(ans.size() && num[i] < ans.back() && k){
             //   cout<<ans;
                ans.pop_back();k--;
         //       cout<<ans<<" "<<k;
            }
            if(ans.size() || num[i]!='0')
                ans+=num[i];
            i++;
        }
//        cout<<ans<<" "<<k;
        while(k){
            ans.pop_back();k--;
        }
        if(ans=="")
            return "0";
        return ans;
    }
};
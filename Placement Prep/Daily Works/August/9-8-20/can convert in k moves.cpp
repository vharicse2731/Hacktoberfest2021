

// https://leetcode.com/problems/can-convert-string-in-k-moves/

/*
Convert string s to t 

Eg:
"input"  "output"  k=9 -->true
i -> o = 6
n -> u = 7

max(6,7)=7 < 9 -->true;

"abc"  "bcd" k=10

a -> b = 1 -> 1
b -> c = 1 -> 1+26*1 =27
c -> d = 1 -> 1+26*2 =53

--> 53 > 10(K) --> false

*/


USING MAP:

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        unordered_map<int, int> m;
        
        for (int i = 0;i < s.length();i++) {
            int sh = (int)t[i] - (int)s[i];
            if (sh < 0) sh += 26;
            m[sh]++;
        }
        for (auto it : m) {
            int val = it.first;
            int cnt = it.second;
            //cout << val << " " << cnt << endl;
            if (val == 0) continue;
            if (k < val + (cnt-1) * 26) {
                return false;
            }
        }
        return true;
    }
};

USING VECTOR:

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int m=s.size(),n=t.size();
        if(m!=n)
            return 0;
        vector<int>shift(n,0);
        for(int i=0;i<n;i++){
            if(s[i]==t[i])
                continue;
            if(t[i]>s[i]){
                shift[i]=(t[i]-'b')-(s[i]-'b');
            }
            else{
                shift[i]=26-((s[i]-'b')-(t[i]-'b'));
            }
        }
        for(int a:shift)
            cout<<a<<" ";
        cout<<endl;
        sort(shift.begin(),shift.end());
        int maxi=shift[0];
        for(int i=1;i<n;i++){
            if(shift[i]==0)
                continue;
            int x=shift[i-1],y=1;
            while(i<n && x==shift[i]){
                shift[i]=shift[i]+(26*y);
                i++;y++;                        
            }
            maxi=max(maxi,shift[i-1]);
        }
        maxi=max(maxi,shift[m-1]);
        if(maxi<=k)
            return 1;
        return 0;
    }
};
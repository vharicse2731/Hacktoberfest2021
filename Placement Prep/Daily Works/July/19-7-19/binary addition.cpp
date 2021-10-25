


Effi:
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        std::string result = "";
        int carry = 0;
        
        while(i >= 0 || j >= 0)
        {
            int sum = carry;
            if(i >= 0)
                sum += (a[i--] - '0');
            
            if(j >= 0)
                sum += (b[j--] - '0');
            
            result.insert(result.begin(), sum % 2 + '0');
            carry = sum / 2;
        }
        if(carry > 0)
            result.insert(result.begin(), '1');
        
        return result;
    }
};

My sol:
class Solution {
public:
    string add(int a,int b,int *c){
 //       cout<<"a:"<<a<<" b:"<<b<<" c:"<<*c<<endl;
        if(a && b && *c){
            *c=1;
            return "1";
        }
        if(a && b){
            *c=1;
            return "0";
        }    
        if(a && *c || b && *c){
            *c=1;
            return "0";
        }
        if(a || b){
            *c=0;
            return "1";
        }
        if(*c){
            *c=0;
            return "1";
        }
        *c=0;
        return "0";
        
    }
    string addBinary(string a, string b) {
        string ans="";
        int c=0;
        int i=a.size(),j=b.size();
        while(i&&j){
            ans+=add(a[i-1]-'0',b[j-1]-'0',&c);
            i--;j--;
        }
        while(i){
            ans+=add(a[i-1]-'0',0,&c);  
            i--;
        }
        while(j){
            ans+=add(b[j-1]-'0',0,&c);  
            j--;
        }
        if(c){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
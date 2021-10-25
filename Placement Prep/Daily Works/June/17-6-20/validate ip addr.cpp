
//https://leetcode.com/problems/validate-ip-address/

Normal:

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP=="")
            return "Neither";
        stringstream ss(IP);
        string temp;
        if(count(IP.begin(),IP.end(),':') > 7 || count(IP.begin(),IP.end(),'.')>3 || IP.find("::")!=string::npos)
            return "Neither";
        if(IP[IP.size()-1]=='.' || IP[IP.size()-1]==':')
            return "Neither";
        
        if(IP.find('.')!=string::npos && count(IP.begin(),IP.end(),'.')==3){
            while(getline(ss,temp,'.')){
                if(temp.size()>1 && temp[0]=='0'){
                //    cout<<1;
                    return "Neither";
                }
                
                if(temp.size()>4 || temp.size()==0){
            //        cout<<2;
                    return "Neither"; 
                }
                
                for(int i=0;i<temp.size();i++){
                    if(!isdigit(temp[i]))
                        return "Neither";
                }
                
                if(stoi(temp)>255)
                    return "Neither";
                
            }
            return "IPv4";
        }
        else if (count(IP.begin(),IP.end(),':')==7){
            while(getline(ss,temp,':') ){
                if(temp.size()>4 || temp.size()==0)
                    return "Neither";  
                
                for(auto c:temp){
                    // if(c=='+' || c=='-')
                    //     return "Neither";
                    if(!isdigit(c) && (!isalpha(c) || toupper(c)>'F'))
                        return "Neither";
                }
            }   
            return "IPv6";
        }
        return "Neither";
    }
};

Reg Expr:

class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"), ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");   // create regex object for regulare expression
        if(regex_match(IP, ipv4)) // match regex expression with given IP string for IPv4
            return "IPv4";
        else if(regex_match(IP, ipv6)) // match regex expression with given IP string for IPv6
            return "IPv6";
        return "Neither"; // Otherwise return "Neither"
    }
};
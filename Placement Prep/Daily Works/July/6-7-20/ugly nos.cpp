
//  https://leetcode.com/problems/ugly-number/submissions/

class Solution {
public:
    bool isUgly(int num) {
        if(num<1)
            return 0;
        if(num==1)
            return 1;
        bool temp;
        
        do{
            temp=false;
            if(num%5==0){
                num/=5;temp=true;
            }
            if(num%3==0){
                num/=3;temp=true;
            }
            if(num%2==0){
                num/=2;temp=true;
            }
        }while(temp && num!=1);
        
        if(temp && num==1)
            return true;
        return false;
    }
};



bool isUgly(int num){
    if (num <= 0) return false;
    while(num % 3 == 0) num /= 3;
    while(num % 5 == 0) num /= 5;
    return (num  & (num - 1)) == 0; // checks for powers of 2 :/
}
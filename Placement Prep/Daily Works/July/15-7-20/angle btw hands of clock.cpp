

//https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
		double ans=abs(30*hour+0.5*minutes)-6*minutes;
		return min(ans, 360-min);
    }
};

Mine:
class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double hr=((hour*60+minutes)*0.5);
        double min=(minutes*6)%360;
        double temp1;
        if(hr>min){
            temp1=360-hr+min;  
        }
        else
            temp1=360-min+hr;
        if(temp1>abs(hr-min))
            return abs(hr-min);
        else
            return temp1;
    }
};
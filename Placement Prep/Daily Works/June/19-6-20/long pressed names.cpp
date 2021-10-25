

Your friend is typing his name into a keyboard.  
Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  
Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.


// https://leetcode.com/problems/long-pressed-name/


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
                
        int i=0,j=0;
        while(i<name.size()-1 && j<typed.size()-1){
            if(name[i+1]==typed[j+1]){
                i++;j++;
            }
            else if(typed[j+1]==name[i])
                j++;
            else
                return false;
        }
        while(j<typed.size()-1){
            if(name[i]==typed[j+1])
                j++;
            else
                return false;
        }
        if(i==name.size()-1 && j==typed.size()-1 && name[i]==typed[j])
            return true;
        return false;
    }
};
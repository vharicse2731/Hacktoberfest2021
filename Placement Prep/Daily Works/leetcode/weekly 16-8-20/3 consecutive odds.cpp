


//https://leetcode.com/contest/weekly-contest-202/problems/three-consecutive-odds/

//Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.


bool threeConsecutiveOdds(vector<int>& arr) {
        int c=0;
        for(int a:arr){
            if(a&1)
                c++;
            else
                c=0;
            if(c==3)
                return 1;
            
        }
        return 0;
    }
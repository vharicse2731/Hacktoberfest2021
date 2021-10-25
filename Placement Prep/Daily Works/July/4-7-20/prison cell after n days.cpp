

//  https://leetcode.com/problems/prison-cells-after-n-days/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N==0)
            return cells;
        vector<int>temp;
        temp=cells;
        for(int j=1;j<7;j++){
            if(temp[j-1]==temp[j+1])
                cells[j]=1;
            else
                cells[j]=0;
        }
        cells[0]=cells[7]=0;
        // for(auto it:cells)
        //         cout<<it<<" ";
        // cout<<endl;
        N=(N-1)%14;
        for(int i=0;i<N;i++){
            temp=cells;
            for(int j=1;j<7;j++){
                if(temp[j-1]==temp[j+1])
                    cells[j]=1;
                else
                    cells[j]=0;
            }
            // for(auto it:cells)
            //     cout<<it<<" ";
            // cout<<endl;
        }
        return cells;
    }
};
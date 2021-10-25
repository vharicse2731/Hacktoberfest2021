


// https://leetcode.com/problems/set-matrix-zeroes/



USING SET:

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>row;
        set<int>col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }     
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(row.count(i) || col.count(j))
                    matrix[i][j]=0;
            }
        }
    }
};


OPTIMAL O(1) space:
more optimize by doing 2 seperate loops for r and c finding and stats with i=1,j=1;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r=false,c=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    if(!i)
                        r=1;
                    if(!j)
                        c=1;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }     
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j]=0;
            }
        }
        if(r)
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
        if(c)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
    }
};
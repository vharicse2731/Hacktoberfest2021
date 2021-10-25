
// MOVE ZEROS IN A ARRAY TO BACK

/*
2 0 4 0 --> 2 4 0 0
*/

void moveZeroes(vector<int>& nums) {
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(!nums[i])
                continue;
         //   swap(nums[i],nums[j]);
            nums[j]=nums[i];
            j++;
        }
        while(j<n){
            nums[j++]=0;
        }
    }
	
	
void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
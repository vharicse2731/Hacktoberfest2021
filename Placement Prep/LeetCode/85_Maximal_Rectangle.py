class Solution:
    
    def calc_max_area(self, arr):
        pos_stack = []
        ht_stack = []
        largest_area = 0
        
        tmp_pos = 0
        tmp_ht = 0
        
        i= 0
        
        while(i<len(arr)):
            if (len(ht_stack)==0 or arr[i]>ht_stack[-1]):
                ht_stack.append(arr[i])
                pos_stack.append(i)
            elif arr[i]<ht_stack[-1]:
                while(len(ht_stack)>0) and (arr[i]<ht_stack[-1]):
                    tmp_pos = pos_stack.pop()
                    tmp_ht = ht_stack.pop()
                    tmp_area = tmp_ht*(i-tmp_pos)
                    largest_area = max(largest_area, tmp_area)
                ht_stack.append(arr[i])
                pos_stack.append(tmp_pos)
            i+=1
            
        while(len(ht_stack)>0):
            tmp_pos = pos_stack.pop()
            tmp_ht = ht_stack.pop()
            tmp_area = tmp_ht*(i-tmp_pos)
            largest_area = max(largest_area, tmp_area)
            
        return largest_area

                    
        
    
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        
        if not matrix:
            return 0
        
        calc_arr = [0 for _ in range(len(matrix[0]))]
        
        max_area = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == "0":
                    calc_arr[j] = 0
                else:
                    calc_arr[j]+=int(matrix[i][j])
            
            area = self.calc_max_area(calc_arr)
            max_area = max(max_area, area)
            
            
        return max_area

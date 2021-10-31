class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        if len(heights) == 0:
            return 0
        
        if len(heights)==1:
            return heights[0]
        
        positions = []
        hts = []
        
        max_ht = 0
        top = 0
        positions.append(0)
        hts.append(heights[0])
        for i in range(1,len(heights)):
            if heights[i]>= hts[-1]:
                positions.append(i)
                hts.append(heights[i])
                
            else:
                
                while((len(hts)>0) and (heights[i]<hts[-1])):
                    curr_ht = hts.pop()
                    top = positions.pop()
                    curr_area = curr_ht*(i-top)
                    max_ht = max(max_ht, curr_area)
                    
                if len(hts)==0 or (heights[i]>hts[-1]):
                    positions.append(top)
                    hts.append(heights[i])
        
        i = len(heights)              
        while(len(hts)>0):
            curr_ht = hts.pop()
            curr_area = curr_ht*(i-positions.pop())
            max_ht = max(max_ht, curr_area)
                      
        return max_ht

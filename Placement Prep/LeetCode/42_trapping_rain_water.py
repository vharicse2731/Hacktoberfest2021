class Solution:
    def trap(self, height: List[int]) -> int:
        
        if not height:
            return 0
        
        lft_max = [0 for _ in range(len(height))]
        
        rgt_max = [0 for _ in range(len(height))]

        lft_max[0] = height[0]
        
        maxht = height[0]
        
        for i in range(1, len(height)):
            if height[i]>maxht:
                maxht = height[i]
                
            lft_max[i] = maxht
            
        maxht = height[-1]
        rgt_max[-1] = height[-1]
        
        for i in range(len(height)-2, -1, -1):
            if height[i]>maxht:
                maxht = height[i]
                
            rgt_max[i] = maxht
        
        water = 0
        
        for i in range(1, len(height)-1):
            min_ht = min(lft_max[i], rgt_max[i])
            vol = abs(height[i]-min_ht)
            water+=vol
            
        return water

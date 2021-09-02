    int maxArea(vector<int>& height) {
         int maxWater=0;
        
        int i=0; int j=height.size() -1;
        
        while(i<j)
        {
            int l=j-i;
            int h=min(height[i], height[j]);
            int water = l* h;
           
            
            maxWater=max(maxWater, water);
            
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return maxWater;
    }
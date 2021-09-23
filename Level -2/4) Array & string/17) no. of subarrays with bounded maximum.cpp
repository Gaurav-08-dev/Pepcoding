int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
         
        int i=0,j=0,count=0,pc=0;
        while(j<nums.size())
        {
            if(nums[j]>=left and nums[j]<=right)
            {
                pc=j-i+1;
                count+=pc;
            }
             
            else if(nums[j]<left)
            {
                count+=pc;
            }
            
            else
            {
                pc=0;
                i=j+1;
            }
            

            j++;
            
        }
        
        return count;
    }
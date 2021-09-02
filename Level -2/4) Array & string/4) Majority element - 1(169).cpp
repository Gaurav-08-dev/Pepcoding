int majorityElement(vector<int>& nums) {
        
    if(nums.size()==1)
    {
        return nums[0];
    }
        int count=1;
        int index=0;
       for(int i=1;i<nums.size();i++)
       {
           if(nums[index]==nums[i])
           {
               count++;
           }
           else
           {
               count--;
           }
           if(count==0)
           {
               index=i;
               count=1;
           }
       }
        
        return nums[index];
        
    }
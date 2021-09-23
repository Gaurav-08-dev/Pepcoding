 bool checkFrequency(vector<int>&nums,int val)
    {
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                count++;
            }
        }
        
        return count > nums.size()/3;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size()==1) return {nums[0]};
        
        int val1=nums[0],count1=1;
        int val2=nums[0],count2=0;
        
        int i=1;
        while(i<nums.size())
        {
            if(val1==nums[i])
            {
                count1++;
            }
            else if(val2==nums[i])
            {
                count2++;
            }
            else
            {
                if(count1==0)
                {
                    val1=nums[i];
                    count1=1;
                }
                else if(count2==0)
                {
                    val2=nums[i];
                    count2=1;
                }
                else
                {
                    count1--;count2--;
                }
            }
            i++;
        }
        vector<int> ans;
        if(checkFrequency(nums,val1))
        {ans.push_back(val1);}
        
        if(val1==val2) return ans; 
        if(checkFrequency(nums,val2))
        {ans.push_back(val2);}
        
        return ans;
    }
/* Two pass approach */
int maxProduct(vector<int>& nums) {
        
         int prod=1;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                prod=1;
                res=max(res,nums[i]);
            }
            else
            {
                prod*=nums[i];
                res=max(res,prod);
            }
        }
        
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                prod=1;
                res=max(res,nums[i]);
            }
            else
            {
                prod*=nums[i];
                res=max(res,prod);
            }
        }
        
        
        return res;
    }

    
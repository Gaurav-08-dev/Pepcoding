 int maxSubArray(vector<int>& nums) {
        
    int curr_max=nums[0],ans=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            curr_max=max(nums[i],nums[i]+curr_max);
            ans=max(ans,curr_max);
        }
        
        return ans;
    }



/* implementation -> 2*/

    int curr_max=0,ans=0;

    for(int i=0;i<arr.size();i++)
    {
        if(curr_max<0)
            curr_max=arr[i];
        else
        {
            curr_max+=arr[i];
        }
        ans=max(ans,curr_max);
    }

    return ans;
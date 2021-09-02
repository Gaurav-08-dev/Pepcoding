vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        
        int l=0,r=nums.size()-1;
        
        for(int k=nums.size()-1;k>=0;k--)
        {
            if(nums[l]*nums[l] > nums[r]*nums[r])
            {
                ans[k]=nums[l]*nums[l] ;
                l++;
            }
            else
            {
                ans[k]=nums[r]*nums[r] ;
                r--;
            }
        }
        
        return ans;
        
    }
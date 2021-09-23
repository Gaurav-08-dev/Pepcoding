    vector<int> sortArrayByParity(vector<int>& nums) {
        
        if(nums.size()==1) return nums;
        int l=0,r=nums.size()-1;
        
        while(l < r)
        {
            if(nums[l]%2==1 and nums[r]%2==0)
            {
                swap(nums[l],nums[r]);
                l++;r--;
            }
            else if(nums[l]%2==0)
            {
                l++;
            }
            else if(nums[r]%2==1)
            {
                r--;
            }
        }
        return nums;
    }


    /* Preserving postions*/
    void solve(vector<int> &nums)
{
     
        int l=0,r=0;
        
        while(l < nums.size())
        {
            if(nums[l]%2==0)
            {
                swap(nums[l],nums[r]);
                l++;r++;
            }
            else 
            {
                l++;
            }
        }
}

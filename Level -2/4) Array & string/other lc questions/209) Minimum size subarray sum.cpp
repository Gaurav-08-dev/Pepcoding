int minSubArrayLen(int target, vector<int>& nums) {
    
    int n=nums.size();
    int left=0,right=0;
    int sum=0;
    int maxLength=INT_MAX;
    while(right<n)
    {
        sum+=nums[right++];
        while(sum>=target)
        {
            maxLength=min(maxLength,right-left);
            sum-=nums[left++];
        }
    }
    
    return maxLength==INT_MAX?0:maxLength;
    
}
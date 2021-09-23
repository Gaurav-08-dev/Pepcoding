
/* TC & SC -> O(N)*/
int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();
        
//         right min
        vector<int> rightMin(n);
        rightMin[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rightMin[i]=min(nums[i],rightMin[i+1]);
        }
        
        int leftMax=INT_MIN;
        
        for(int i=0;i<n-1;i++)
        {
            leftMax=max(leftMax,nums[i]);
            if(leftMax<= rightMin[i+1])
            {
                return i+1;                
            }
        }
        return -1;
    }


/* TC -> O(n) & sc-> O(1)*/

int partitionDisjoint(vector<int>& arr) {
  
    
    int greater=arr[0],leftMax=arr[0],ans=0;
    
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] > greater)
        {
            greater=arr[i];
        }
        if(arr[i] < leftMax)
        {
            ans=i;
            leftMax=greater;
        }
    }
    
    return ans+1;

}
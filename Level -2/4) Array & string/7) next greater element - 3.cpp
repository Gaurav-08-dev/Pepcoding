    bool res(string& nums)
    {
        int i=nums.size()-1;
        while(i>0 and nums[i]<=nums[i-1])
        {
            i--;
        }
        
        
        if(i==0) return false;
        int j=nums.size()-1;
        
        while(j >0 and nums[j]<=nums[i-1]) j--;
        
        swap(nums[j],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
        return true;
        
    }
    int nextGreaterElement(int n) {
        
        string num = to_string(n);
        bool ans=res(num);
        size_t x=stoll(num);
        return (!ans or x>INT_MAX)? -1 : x;
    }
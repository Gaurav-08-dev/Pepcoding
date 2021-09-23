/* Two pointers approach*/


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> v;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++)
    {
        if(i > 0 and nums[i]==nums[i-1]) continue;
        
        int v2=i+1,v3=nums.size()-1;
        
        while(v2 < v3)
        {
            int sum=nums[i] + nums[v2] + nums[v3];
            
            if(sum==0){
                
                v.push_back({nums[i] ,nums[v2] , nums[v3]});
                
                int val=nums[v2];
                while(v2 < v3 and nums[v2]==val)
                {
                    v2++;
                }
                
                int val2=nums[v3];
                while(v3 > v2 and nums[v3]==val2)
                {
                    v3--;
                }
            }
            
            else if(sum > 0)
            {
                v3--;
            }
            else if(sum < 0)
            {
                v2++;
            }
            
        }
    }
    return v;
}



/* HASHMAP approach */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size() < 3) return v;
        
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i] > 0 ) break;
            if( i > 0 and nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int target= -(nums[i]+nums[j]);
                
                if(m.count(target) and m.find(target)->second > j)
                {
                    v.push_back({target,nums[i],nums[j]});
                }
                // cout<<nums[j]<<" -> ";
                j=m.find(nums[j])->second;
                // cout<<j<<" ";
            }
            i=m.find(nums[i])->second;
        }
        
        return v;
    }
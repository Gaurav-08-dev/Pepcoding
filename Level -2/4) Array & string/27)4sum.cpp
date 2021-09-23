 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        if(nums.size() < 4) return v;
        
        
        sort(nums.begin(),nums.end());
        
      for(int i=0;i<nums.size();i++)
        {
          if(i > 0 and nums[i]==nums[i-1]) continue;
          for(int j=i+1;j<nums.size();j++)
          {
              if(j > i+1 and nums[j]==nums[j-1]) continue;
            int new_target=target - nums[i] - nums[j];
              
            int v2=j+1,v3=nums.size()-1;
            
            while(v2 < v3)
            {
                int sum= nums[v2] + nums[v3];
                
                if(sum==new_target){
                    
                    v.push_back({nums[i],nums[j] ,nums[v2] , nums[v3]});
                    
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
                
                else if(sum > new_target)
                {
                    v3--;
                }
                else if(sum < new_target)
                {
                    v2++;
                }
                
            }
              
              // while(j+1 < nums.size() and nums[j+1]==nums[j]) ++j;
        }
          // while(i+1 < nums.size() and nums[i+1]==nums[i]) ++i;
      }
        
        return v;
        
    }
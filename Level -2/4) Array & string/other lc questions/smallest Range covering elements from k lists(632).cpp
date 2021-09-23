 vector<int> smallestRange(vector<vector<int>>& nums) {
         int n=nums.size();
        
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        int mn=INT_MAX,mx=INT_MIN,range=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i][0],{i,0}});
            mn=min(mn,nums[i][0]);
            mx=max(mx,nums[i][0]);
            
        }
        
        int a=mn,b=mx;
        while(!pq.empty())
        {
           
            pi curr=pq.top();
            pq.pop();
            
            if(curr.second.second + 1 < nums[curr.second.first].size())
            {
                int r=curr.second.first, c=curr.second.second+1;
                pq.push({nums[r][c],{r,c}});
                
                mn=pq.top().first;
                mx=max(mx,nums[r][c]);
                if(b-a > mx-mn)
                {
                    a=mn;
                    b=mx;
                }
            }
            else
            {
                break;
            }
        }
        
        return {a,b};
    }
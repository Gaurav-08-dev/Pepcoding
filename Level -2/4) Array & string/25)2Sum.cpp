/* brute force approach */

/* TC -> O(n^2)*/
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            int k=target-nums[i];
            for(int j=i+1;j<size;j++)
            {
                if(nums[j]==k)
                {
                    index.push_back(i);
                    index.push_back(j);
                    break;
                }
            }
            if(index.size()==2)
                break;
        }
        return index;
    }





 /* 2 - pointer approach */

 /* TC-> O(nlogn) sc-> O(n)*/
  vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end());
        
        int left=0,right=v.size()-1;
        
        int index1=0,index2=0;
        
        while(left < right)
        {
            int sum=v[left].first + v[right].first;
            
            if(sum==target)
            {
                index1=v[left].second;
                index2=v[right].second;
                break;
            }
            
            if(sum < target)
                left++;
            
            if(sum > target)
                right--;
        }
        
        return {index1,index2};
    }


/* Hashmap approach */

/* TC -> O(n)   SC- > O(n)*/

    vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<int> ans;
    unordered_map<int,int> v;
    for(int i=0;i<nums.size();i++)
    {
        if(v.find(target-nums[i])!=v.end())
        {
            ans.push_back(v[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        else
        {
            v[nums[i]]=i;
        }
    }
    
    return ans;
    
    
}

/* TC-> O(nlogn) */

vector<pair<int,int>> solve(vector<int> &arr,int target)
{
    vector<pair<int,int>> ans;
    sort(arr.begin(),arr.end());
    int l=0,r=arr.size()-1;
    
    while(l<r)
    {
        if(l!=0 and arr[l]==arr[l-1])
        {
            l++;
            continue;
        }
        int sum=arr[l] + arr[r];
        if(sum==target)
        {
            ans.push_back({arr[l],arr[r]});
            l++; r--;
        }
        else if (sum < target) l++;
        else r--;
    }
    
    return ans;
}


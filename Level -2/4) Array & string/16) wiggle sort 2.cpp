
void solve(vector<int> &nums)
{
         vector<int> duplicate=nums;
        sort(duplicate.begin(),duplicate.end());
        
        int j=nums.size()-1;
        int i=1;
        
        while(i<nums.size())
        {
            nums[i]=duplicate[j];
            j--;
            i+=2;
        }
               
        i=0; 
        while(i<nums.size())
        {
            nums[i]=duplicate[j];
            j--;
            i+=2;
        }
}

void solve(vector<int> &arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        if(i%2==0)
        {
            if(arr[i+1]<arr[i])
                swap(arr[i+1],arr[i]);
        }
        else
        {
            if(arr[i+1]>arr[i])
                swap(arr[i],arr[i+1]);
        }
    }
}
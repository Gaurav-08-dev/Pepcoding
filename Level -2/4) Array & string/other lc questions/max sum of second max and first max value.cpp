long long pairWithMaxSum(long long arr[], long long N)
{
    
    long long maxSum=0;
    
    for(int i=0;i<N-1;i++)
    {
        maxSum=max(maxSum,arr[i]+arr[i+1]);
    }
    return maxSum;
}
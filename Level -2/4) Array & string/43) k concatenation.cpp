#include<bits/stdc++.h>
using namespace std;

int kadanes(vector<int> &narr)
{
    int n=narr.size();
    int cSum=0,oMax=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        if(cSum<0)
        {
            cSum=narr[i];
        }
        else
        {
            cSum+=narr[i];
        }
        oMax=max(cSum,oMax);
    }
    
    return oMax;
}


long long solve(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<int> narr(2*n,0);
    
    for(int i=0;i<n;i++)
    {
        narr[i]=arr[i];
        narr[n+i]=arr[i];
    }
    
    int kadanes_sum=kadanes(narr);
    
    int totalSum=0;
    
    for(int i=0;i<arr.size();i++)
    {
        totalSum+=arr[i];
    }
    
    
    if(totalSum>=0)
    {
        return kadanes_sum + (totalSum * (k-2));
    }
    else
    {
        return kadanes_sum;
    }
}
int main()
{
    int n;
    cin>>n;
    
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    int k;
    cin>>k;
    
    int maxsum=solve(arr,k);
    cout<<maxsum;
}
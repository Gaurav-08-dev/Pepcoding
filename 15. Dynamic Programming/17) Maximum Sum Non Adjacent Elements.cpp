#include<bits/stdc++.h>
using namespace std;

// recursion
int maxSum(vector<int> &arr,int index,bool status)
{
    if(index==-1) return 0;
    
    int m=0;
    
    if(status==false)
    {
        m=max(m,maxSum(arr,index-1,true)) + arr[index];
    }
    
    // exclude call
    m=max(m,maxSum(arr,index-1,false));
    
    return m;
}

// memoization
int maxSum_mem(vector<int> &arr,vector<vector<int>> &dp,int index,int status)
{
    if(index==-1) return dp[index+1][status]=0;
    if(dp[index+1][status]!=0) return dp[index+1][status];
    
    int m=0;
    
    if(status==0)
    {
        m=max(m,maxSum_mem(arr,dp,index-1,1)) + arr[index];
    }
    
    // exclude call
    m=max(m,maxSum_mem(arr,dp,index-1,0));
    
    return dp[index+1][status]=m;
}


// tabulation
int maxSum_tab(vector<int> &arr)
{
    int in=0,ex=0;
    
    for(int i=0;i<arr.size();i++)
    {
        int n_in=ex+arr[i];
        int n_ex=max(in,ex);
        in=n_in;
        ex=n_ex;
    }
    
    return max(in,ex);
}


void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    // cout<<maxSum(arr,dp,n-1,0);
    cout<<maxSum_tab(arr);
}

int main()
{
    solve();
}
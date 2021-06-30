#include<bits/stdc++.h>
using namespace std;


// recursive
int knapsack_rec(vector<int> &value,vector<int> &wt,int index,int cap)
{
    if(index==-1) return 0;
    int v1=0;
    
    // yes call
    if(cap - wt[index]>=0){
        v1=knapsack_rec(value,wt,index-1,cap-wt[index]) + value[index];
    }
    // no call
    int v2=knapsack_rec(value,wt,index-1,cap);
    
    return max(v1,v2);
}


// memoization

int knapsack_mem(vector<int> &value,vector<int> &wt,int index,int cap,vector<vector<int>> &dp)
{
    if(index==-1) return dp[index+1][cap]=0;
    if(dp[index+1][cap]!=0)
    {
        return dp[index+1][cap];
    }
    int v1=0;
    
    // yes call
    if(cap - wt[index]>=0){
        v1=knapsack_mem(value,wt,index-1,cap-wt[index],dp) + value[index];
    }
    // no call
    int v2=knapsack_mem(value,wt,index-1,cap,dp);
    
    return dp[index+1][cap]=max(v1,v2);
}

// tabulation
int knapsack_tab(vector<int> &value,vector<int> &wt,int index,int cap,vector<vector<int>> &dp)
{
    for(int indx=1;indx<=value.size();indx++)
    {
        for(int c=1;c<=cap;c++)
        {
            if(c<wt[indx-1])
            {
                dp[indx][c]=dp[indx-1][c];
            }
            else
            {
                int v1=dp[indx-1][c-wt[indx-1]] + value[indx-1];
                int v2=dp[indx-1][c];
                dp[indx][c]=max(v1,v2);
            }
        }
    }
    
    return dp[value.size()][cap];
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> values;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        values.push_back(t);
    }
    vector<int> weights;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        weights.push_back(t);
    }
    
    int cap;
    cin>>cap;
    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));
    cout<<knapsack_tab(values,weights,n-1,cap,dp);
    
}
#include<bits/stdc++.h>
using namespace std;

// recursion
int unbounded_rec(vector<int> &value,vector<int> &wt,int cap,int index)
{
    if(cap==0 or index==-1) return 0;
    
    
    int v1=0;
    
    if(cap-wt[index]>=0)
    {
        v1=unbounded_rec(value,wt,cap-wt[index],index) + value[index];
    }
    
    int v2=unbounded_rec(value,wt,cap,index-1);
    
    return max(v1,v2);
}

// memoization
int unbounded_mem(vector<int> &value,vector<int> &wt,int cap,int index,vector<vector<int>> &dp)
{
    if(cap==0 or index==-1) return dp[index+1][cap]=0;
    
    if(dp[index+1][cap]!=0) return dp[index+1][cap];
    
    int v1=0;
    
    if(cap-wt[index]>=0)
    {
        v1=unbounded_rec(value,wt,cap-wt[index],index) + value[index];
    }
    
    int v2=unbounded_rec(value,wt,cap,index-1);
    
    return dp[index+1][cap]=max(v1,v2);
} 

// tabulation
int unbounded_tab(vector<int> &value,vector<int> &wt,int cap)
{
    vector<int> dp(cap+1,0);
    
    // outer loop for box
    // inner loop for capacity
    
    for(int i=0;i<value.size();i++)
    {
        for(int c=wt[i];c<=cap;c++)
        {
            // no call
            int v1=dp[c];
            // yes call
            int v2=dp[c-wt[i]] + value[i];
            dp[c]=max(v1,v2);
        }
    }
    
    return dp[cap];
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
    
    cout<<unbounded_tab(values,weights,cap);

}
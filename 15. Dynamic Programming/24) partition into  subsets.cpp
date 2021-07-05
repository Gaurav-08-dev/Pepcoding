#include<bits/stdc++.h>
using namespace std;

// IMPORTANT Question

long subsets(long n, long k)
{
    if(n==k) return 1;
    if(n==0 or k==0) return 0;
    
    return (k)*subsets(n-1,k) + subsets(n-1,k-1);

}

long subsets_mem(int n,int k,vector<vector<long>> &dp)
{
    if(n==k) return dp[n][k]=1;
    if(n==0 or k==0) return dp[n][k]=0;
    
    if(dp[n][k]!=0) return dp[n][k];
    
    long count=0;
    count=k * subsets(n-1,k)+ subsets(n-1,k-1);
    
    return dp[n][k]=count;
}

long subsets_tab(int n,int k)
{
    vector<vector<long>> dp(n+1,vector<long>(k+1,0));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i and j<=k;j++)
        {
            if(j==0) {dp[i][j]=0;}
            else if(j==i) {dp[i][j]=1;}
            else
            {
                dp[i][j]=(j * dp[i-1][j]) + dp[i-1][j-1];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n,k;
    
    cin>>n>>k;
    vector<vector<long>> dp(n+1,vector<long>(k+1));
    
    cout<<subsets_tab(n,k);
    
}
    

#include<bits/stdc++.h>
using namespace std;

// recursion
int countBinary_rec(int n,int lastAdded)
{
    if(n==0) return 1;
    int count=0;
    if(lastAdded==1)
    {
        count+=countBinary_rec(n-1,0);
    }
    count+=countBinary_rec(n-1,1);
    return count;
}

// memoization
int countBinary_mem(int n,int lastAdded,vector<vector<int>> &dp)
{
    if(n==0) return dp[n][lastAdded]=1;
    if(dp[n][lastAdded]!=0)
    {
        return dp[n][lastAdded];
    }
    int count=0;
    if(lastAdded==1)
    {
        count+=countBinary_mem(n-1,0,dp);
    }
    count+=countBinary_mem(n-1,1,dp);
    
    return dp[n][lastAdded]=count;
}

// tabulation
int countBinary_tab(int n)
{
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    
    // outer loop for column and inner for row
    for(int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0] + dp[i-1][1];
    }
    return dp[n-1][0] + dp[n-1][1];
}


// mroe optimized

int countBinary(int n)
{
    int zero=1,one=1;
    
    for(int i=2;i<=n;i++)
    {
        int n_zero=one;
        int n_one=one + zero;
        
        zero=n_zero;
        one=n_one;
    }
    
    return one + zero;
}




int main()
{
    int n;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    cout<<countBinary(n);
}
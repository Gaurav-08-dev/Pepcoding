#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){  //memoization
    // write your code here
    
    if(n==1 or n==0)
    {
        return dp[n]=n;
    }
    
    if(dp[n]!=0)
    {
        return dp[n];
    }
    
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int fib_tab(int n,vector<int> &dp) //tabulation
{
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=d[i-1]+dp[i-2];
    }

    return dp[n];

}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    cout<<fib(n,dp)<<endl;
    return 0;
}
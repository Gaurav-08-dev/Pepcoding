#include<bits/stdc++.h>
using namespace std;

int paint(int n,int m)
{
    vector<int> dp(n+1);
    

    for(int i=1;i<=n;i++)
    {
        if(i<m)
        {
            dp[i]=1;
        }
        else if(i==m) dp[i]=2;
        else
        {
            dp[i]=dp[i-1] + dp[i-m];
        }
    }
    return dp[n];
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    cout<<paint(n,m);
}
#include <bits/stdc++.h>
using namespace std;

// recursive

// i -> current stair
// n-> total stair
int cs_rec(int i,int n,vector<int> &jumps)
{
    if(i==n) return  1;
    
    int count=0;
    
    for(int jump=1;jump<=jumps[i] and jump+i<=n;jump++)
    {
        count+=cs_rec(i+jump,n,jumps);
    }
    return count;
}

// memoization
int cs_mem(int i,int n,vector<int> &jumps,vector<int> &dp)
{
    
    if(i==n) return dp[i]=1;
    
    if(dp[i]!=0) return dp[i];
    
    int count=0;
    
    for(int jump=1;jump<=jumps[i] and jump + i<=n;jump++)
    {
        count+=cs_mem(i+jump,n,jumps,dp);
    }
    
    return dp[n]=count;
}


// Tabulation

int cs_tab(int n,vector<int> &jumps,vector<int> &dp)
{
    for(int i=n;i>=0;i--)
    {
        if(i==n) { dp[i]=1; continue;}
        
        int count=0;
        
        for(int jump=1;jump<=jumps[i] and jump + i<=n;jump++)
        {
            count+=dp[i+jump];
        }
        
     dp[i]=count;
    }
    
    return dp[0];

}


void cs(vector<int> &jumps, int n)
{vector<int> dp(n+1,0);
    cout<<cs_tab(n,jumps,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0 ; i < n ;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cs(arr,n);
}
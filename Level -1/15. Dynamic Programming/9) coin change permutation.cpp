#include<bits/stdc++.h>
using namespace std;



int coinPerm_rec(int n,vector<int> &arr,int amt)
{
    if(amt==0)
    {
        return 1;
    }
    int count=0;
    for(int coin :arr)
    {
        if(amt-coin>=0)
        {
            count+=coinPerm_rec(n,arr,amt-coin);
        }
    }
    return count;
}

int coinPerm_mem(int n,vector<int> &arr,int amt,vector<int> &dp)
{
    if(amt==0)
    {
        return dp[amt]=1;
    }
    
    if(dp[amt]!=0)
    {
        return dp[amt];
    }
    int count=0;
    for(int coin :arr)
    {
        if(amt-coin>=0)
        {
            count+=coinPerm_mem(n,arr,amt-coin,dp);
        }
    }
    return dp[amt]=count;
}


int coinPerm_tab(int n,vector<int> &arr,int amt,vector<int> &dp)
{
    dp[0]=1;
    for(int i=1;i<=amt;i++)
    {
        for(int coin: arr)
        {
            if(i-coin>=0)
                dp[i]+=dp[i-coin];
        }
    }
    return dp[amt];
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

    int amt;
    cin>>amt;
    vector<int> dp(amt+1);
    cout<<coinPerm_tab2(n,arr,amt,dp);
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
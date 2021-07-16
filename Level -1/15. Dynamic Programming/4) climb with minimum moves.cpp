#include<bits/stdc++.h>
using namespace std;

// memoization
int min_mem(int i,int n,vector<int> &jumps,vector<int> &dp)
{
	if(i==n){ return dp[i]=0;}

	if(dp[i]!=0){return dp[i];}

	int minJumps=(int)1e9;

	for(int jump=1;jump<=jumps[i] and jump+i<=n;jump++)
	{
		minJumps=min(minJumps,min_mem(i+jump,n,jumps,dp));
	}

	return minJumps==1e9 ? (dp[i]=minJumps): (dp[i]=minJumps+1);
}




// recursive
int min_rec(int i,int n,vector<int> &jumps)
{
	if(i==n)
	{
		return 0;
	}

	int minJumps=(int)1e9;

	for(int jump=1;jump<=jumps[i] and jump+i<=n;jump++)
	{
		minJumps=min(minJumps,min_rec(i+jump,n,jumps));
	}

	return minJumps==1e9?minJumps:minJumps+1;
}

// tabulation
int min_tab(int i,int n,vector<int> &jumps,vector<int> &dp)
{
	for(int i=n;i>=0;i--)
	{
		if(i==n){ dp[i]=0; continue;}

	

	int minJumps=(int)1e9;

	for(int jump=1;jump<=jumps[i] and jump+i<=n;jump++)
	{
		minJumps=min(minJumps, dp[i+jump]);
	}

		if(minJumps==1e9)
		{
			dp[i]=1e9;
		}
		else
		{
			dp[i]=minJumps + 1;
		}
	}

	return dp[0];
}

void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0 ; i < n ;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> dp(n+1,0);
    int res=min_tab(0,n,arr,dp);
    if(res==1e9)
    	cout<<"null";
    else
    	cout<<res;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
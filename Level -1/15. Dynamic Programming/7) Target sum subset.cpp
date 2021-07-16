#include<bits/stdc++.h>
using namespace std;


// memoization
int targetSum_mem(vector<int> &arr,int target,int index,vector<vector<int>> &dp)
{
    if(target==0) return dp[index][target]=1;
	if(index==arr.size())
	{
		return dp[index][target]=0;
	}

	if(dp[index][target]!=-1)
	{
		return dp[index][target];
	}
	int res=0;
	if(target-arr[index]>=0)
	{
		res=targetSum_mem(arr,target-arr[index],index+1,dp);
	}
	res=res||targetSum_mem(arr,target,index+1,dp);

	return dp[index][target]=res;
}


// recursive
bool targetSum(vector<int> &arr,int target,int index)
{
    if(target==0) return true;
	if(index==arr.size())
	{
		return false;
	}
	bool res=false;
	if(target-arr[index]>=0)
	{
		res=targetSum(arr,target-arr[index],index+1);
	}
	res=res||targetSum(arr,target,index+1);

	return res;
}

// tabulation
bool targetSum_tab1(vector<int> &arr,int target)
{
    int n=arr.size()+1;
    int tSize=target+1;
    bool dp[n][tSize];

	for(int index=0;index<n;index++)
	{
		for(int target=0;target<tSize;target++)
		{
			if(target==0)
			{
				dp[index][target]=true;
			}
			else if (index==0)
			{
				dp[index][target]=false;
			}
			else
			{
				int val=arr[index-1];
				if(target < val)
				{
					// only no call
					dp[index][target]=dp[index-1][target]; 
				}
				else
				{
					//  no call || yes call
					dp[index][target]=dp[index-1][target] || dp[index-1][target-val];
				}
			}
		}
	}
	
	return dp[n-1][tSize-1];
}

int targetSum_tab2(vector<int> &arr,int target)
{
	    int n=arr.size()+1;
    int tSize=target+1;
    bool dp[n][tSize];

    for(int index=arr.size()-1;index>=0;index--)
    {
    	for(int targ=0;targ<=target;targ++)
    	{
    		if(targ==0) {dp[index][targ]=1; continue;}
			if(index==arr.size())
			{
				dp[index][targ]=0;continue;
			}
			int res=0;
			if(targ-arr[index]>=0)
			{
				res=dp[index+1][targ - arr[index]];
			}
			res=res||dp[index+1][targ];
			dp[index][targ]=res;
    	}
    }

	return dp[0][target];
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

	int target;
	cin>>target;

	vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

	if(targetSum_tab1(arr,target))
	{cout<<"true";}
	else
	{cout<<"false";}
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
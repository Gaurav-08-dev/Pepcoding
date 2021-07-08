#include<bits/stdc++.h>
using namespace std;


int count_subset(vector<int> &arr,int target)
{
	vector<vector<int>> dp(arr.size()+1,vector<int>(target+1,0));

	for(int i=0;i<dp.size();i++)
	{
		for(int j=0;j<dp[0].size();j++)
		{
			if(i==0 and j==0) dp[i][j]=1;
			else if(i==0) dp[i][j]=0;
			else if(j==0) dp[i][j]=1;
			else
			{
				int val=arr[i-1];

				if(j < val) dp[i][j]=dp[i-1][j];
				else
				{
					dp[i][j]= dp[i-1][j] + dp[i-1][j-val];
				}
			}
		}
	}

	return dp[dp.size()-1][dp[0].size()-1];
}
void solve()
{
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		arr.push_back(t);
	}

	int target;
	cin>>target;

	cout<<count_subset(arr,target);	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
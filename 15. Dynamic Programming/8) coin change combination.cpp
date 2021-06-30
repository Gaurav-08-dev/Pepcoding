#include<bits/stdc++.h>
using namespace std;


// recursion 
int coinComb_rec(vector<int> &arr,int amt,int index)
{
	if(index==0) return 1;

	if(index=arr.size()) return 0;
	int count=0;
	if(target-arr[index]>=0)
	{
		count+=coinPerm_rec(arr,amt-arr[index],index);
	}
	count+=coinPerm_rec(arr,amt,index+1);
	return count;
}


// tabulation
int coinComb_tab(int n,vector<int> &arr,int amt)
{
	vector<int> dp(amt+1);
	dp[0]=1;

	for(int i=0;i<arr.size();i++)
	{
		for(int j=arr[i];j<dp.size();j++)
		{
			dp[j]+=dp[j-arr[i]];
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
 
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
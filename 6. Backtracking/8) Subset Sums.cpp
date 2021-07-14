#include<bits/stdc++.h>
using namespace std;

// brute force approach-> use power set approach

// efficient approach
// Time complexity-> 2^n * log(n) (for sorting) -> for every index we have two options either pick up or not pick up


void print(vector<int> &arr,int N, int index,int sum,vector<int> &ans)
{
    if(index==N)
    {
        ans.push_back(sum);
        return ;
    }
    print(arr,N,index+1,sum+arr[index],ans);
    print(arr,N,index+1,sum,ans);
}

vector<int> subsetSums(vector<int>&arr, int N)
{
    vector<int> ans;
    print(arr,N,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
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
	vector<int> ans=subsetSums(arr,n);

	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<"\n";
	}
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}


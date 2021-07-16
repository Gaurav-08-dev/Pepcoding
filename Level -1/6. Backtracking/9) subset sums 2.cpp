/*

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<int> &arr,int N, int index,string sum,vector<string> &ans)
{
    if(index==N)
    {
        ans.push_back(sum);
        return ;
    }
    print(arr,N,index+1,sum+to_string(arr[index]),ans);
    print(arr,N,index+1,sum,ans);
}

vector<string> subsetSums(vector<int>&arr, int N)
{
    vector<string> ans;
    print(arr,N,0,"",ans);
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
	vector<string> ans=subsetSums(arr,n);

	for(int i=0;i<ans.size();i++)
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
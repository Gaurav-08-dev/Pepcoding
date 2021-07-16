#include<bits/stdc++.h>
using namespace std;


int solve(int arr[],int idx,int n)
{
	if(idx>n)
	{
		return INT_MIN;
	}

	int res=solve(arr,idx+1,n);

	return max(res,arr[idx]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	cout<<solve(a,0,n);
}
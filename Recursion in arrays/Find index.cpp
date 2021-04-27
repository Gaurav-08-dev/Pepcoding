#include<bits/stdc++.h>
using namespace std;


bool find(int arr[],int index,int x)
{
	if(arr[index]==x)
	{
		return true;
	}
	else
	{
		find(arr,index+1,x);
	}
	
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	cout<<find(a,0,10);
}
#include<bits/stdc++.h>
using namespace std;


bool check_prime(int temp)
{
	for(int i=2;i*i<=temp;++i)
	{
		if(temp%i==0)
		{
			return false;
		}
	}
	return true;
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
	int temp;
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		if(!check_prime(temp))
		{
			cout<<temp<<" ";
		}
	}




}
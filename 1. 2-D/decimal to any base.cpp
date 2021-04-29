#include<bits/stdc++.h>
using namespace std;

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int n,b;
	cin>>n>>b;

	int sum=0;
	int exp=0;
	while(n>0)
	{
		int rem=n%b;
		sum+=rem*pow(10,exp);
		// cout<<sum;
		n=n/b;
		exp++;
	}

	cout<<sum;
}
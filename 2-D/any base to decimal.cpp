// 1. You are given a number n.
// 2. You are given a base b. n is a number on base b.
// 3. You are required to convert the number n into its corresponding value in decimal number system


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
		int rem=n%10;
		sum+=rem*pow(b,exp);
		n=n/10;
		exp++;
	}

	cout<<sum<<"\n";

}

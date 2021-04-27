#include<bits/stdc++.h>
using namespace std;

void decrease(int n)
{
	if(n<=0)
	{
		return;
	}
	cout<<n<<" ";
	decrease(n-1);
}

void increase(int n)
{
	if(n<=0)
	{
		return;
	}
	increase(n-1);
	cout<<n<<" ";
}


void decrease_increase(int n)
{
	if(n<=0)
	{
		return;
	}
	cout<<n<<"\n";
	decrease_increase(n-1);	
}

void increase_decrease(int n,int i)
{
	if(i==n)
	{
		cout<<n<<"\n";
		return;
	}
	cout<<i<<"\n";
	increase_decrease(n,i+1);
	cout<<i<<"\n";
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int n;
	cin>>n;

	// decrease(n);
	// increase(n);
	// decrease_increase(n);
	int i=1;
	increase_decrease(n,i);
}
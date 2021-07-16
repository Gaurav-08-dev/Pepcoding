#include<bits/stdc++.h>
using namespace std;


int a[100];


// function that returns the Fibonacci number at given index
int fib(int n)  //using memoization
{
	if(n<=1)
	{
		a[n]=n;
		return n;
	}
	else
	{
		if(a[n-2]==-1)
		{
			a[n-2]=fib(n-2);
		}
		if(a[n-1]==-1)
		{
			a[n-1]=fib(n-1);
		}

		return fib(n-2)+fib(n-1);	
	}
}

void fib2(int n)
{
	int x=-1,y=1;
	for(int i=0;i<=n;i++)
	{
		int temp=x+y;
		cout<<temp<<" ";
		x=y;
		y=temp;

	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		a[i]=-1;
	}
	fib2(1);


}
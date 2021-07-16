#include<bits/stdc++.h>
using namespace std;

	

void display(int** a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}


void solve(int** a,int n)
{
	
	for(int i=0;i<n;i++)
	{
		int lc=0;
		for(int j=1;j<n;j++)
		{
			if(a[i][j]<a[i][lc])
			{
				lc=j;
			}
		}

		bool flag=true;
		for(int row=0;row<n;row++)
		{
			if(a[row][lc]>a[i][lc])
			{
				flag=false;
				break;
			}
		}

			if(flag==true)
		{
			cout<<a[i][lc]<<"\n";
			return;
		}

	}

	cout<<"Invalid input"<<"\n";
}





int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	int** a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	// display(a,n);
	solve(a,n);
	delete a;


}
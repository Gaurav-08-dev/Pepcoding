#include<bits/stdc++.h>
using namespace std;


void solve(int** a,int n,int m)
{
	int row=0,col=0;
	int direction=0;

	while(row>=0 and row<n and col>=0 and col<m)
	{
		direction=(direction + a[row][col])%4;
		if(direction==0)
		{
			col++;
		}
		else if(direction==1)
		{
			row++;
		}
		else if(direction==2)
		{
			col--;
		}
		else
		{
			row--;
		}
	}

	// management of invalid coordinates

	if(direction==0)
	{
		col--;
	}
	else if(direction==1)
	{
		row--;
	}
	else if(direction==2)
	{
		col++;
	}
	else
	{
		row++;
	}

	cout<<row<<"\n"<<col<<"\n";

}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	int** a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	solve(a,n,m);






}
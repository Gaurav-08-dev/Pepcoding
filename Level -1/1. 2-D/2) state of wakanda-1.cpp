#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n1,m1;
	cin>>n1>>m1;

	int arr[n1][m1];

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			cin>>arr[i][j];
		}
	}


	// answer starts

	for(int col=0;col<m1;col++)
	{
		if(col%2==0) //move down in row
		{
			for(int row=0;row<n1;row++)
			{
				cout<<arr[row][col]<<"\n";
			}
		}
		else
		{
			for(row=n1-1;row>=0;row--)
			{
				cout<<arr[row][col]<<"\n";
			}
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
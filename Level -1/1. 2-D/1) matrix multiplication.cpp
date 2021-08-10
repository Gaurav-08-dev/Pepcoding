#include<bits/stdc++.h>
using namespace std;

int main()
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

	int n2,m2;
	cin>>n2>>m2;

	int arr2[n2][m2];

	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<m2;j++)
		{
			cin>>arr2[i][j];
		}
	}

	// checking for invalid input
	if(m1!=n2)
	{
		cout<<"Invalid input"<<"\n";
		exit();
	}
	
	// multiplying

	int ans[n1][m2];

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			int val=0;
			for(int k=0;k<n2;k++)
			{
				val+=arr1[i][k] * arr2[k][j];
			}
			ans[i][j]=val;
		}
	}


	// display result
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			cout<<ans[i][j];
		}
	}


}
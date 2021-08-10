#include<bits/stdc++.h>
using namespace std;




/*

Rotate by 90 anticlockwise -> transpose + reverse elements in each columns

Rotate by 180 degree -> reverse element in each row + reverse element in each column

*/

// without extra space approach
void rotate(vector<vector<int>> &arr)
{
	/* first transpose the matrix */

	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<=i;j++)
		{
			int temp;
			temp=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=temp;
		}
	}

	/* Reverse each row of the transposed matrix */

	for(int i=0;i<arr.size();i++)
	{
		int start=0,end=arr.size()-1;

		while(start<=end)
		{
			int temp=arr[i][start];
			arr[i][start]=arr[i][end];
			arr[i][end]=temp;
			start++; end--;
		}
	}


	for(int j=0;j<arr.size();j++)
	{
		for(int i=0;i<arr[0].size();i++)
		{
			cout<<arr[j][i]<<" ";
		}
		cout<<"\n";
	}
}


/* Inplace rotation */

void rotateInplace(vector<vector<int>> &arr)
{

}
void solve()
{
	int n;	
	cin>>n;

	vector<vector<int>> arr;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		arr.push_back(temp);
	}

	rotate(arr);

	print(res);

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
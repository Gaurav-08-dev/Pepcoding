#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n1;
	cin>>n1;

	int arr[n1][n1];

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n1;j++)
		{
			cin>>arr[i][j];
		}
	}

	// answer starts

	for(int gap=0;gap<n1;gap++)
	{
		for(int i=0,j=gap;i<n1,j<n1;i++,j++)
		{
				cout<<arr[i][j]<<"\n";
		}
	}
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
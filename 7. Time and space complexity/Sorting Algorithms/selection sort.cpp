#include<bits/stdc++.h>
using namespace std;


void selection_sort(vector<int> &arr)
{
	int n=arr.size();
	for(int i=0;i<n-1;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[minIndex];
		arr[minIndex]=temp;
	}

	for(auto i: arr)
	{
		cout<<i<<" ";
	}
}

void solve()
{
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}
	selection_sort(arr);
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
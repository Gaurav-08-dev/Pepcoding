#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
	for(auto i : arr)
	{
		cout<<i<<" ";
	}
}
void bubble_sort(vector<int> &arr)
{
	for(int i=0;i<arr.size()-1;i++)
	{
		for(int j=1;j<arr.size()-i;j++)
		{
			if(arr[j]<arr[j-1])
			{
				int temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
		print(arr);
		cout<<"\n";
	}

	// for(int i=0;i<arr.size();i++)
	// {
	// 	cout<<arr[i]<<" ";
	// }
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
	bubble_sort(arr);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
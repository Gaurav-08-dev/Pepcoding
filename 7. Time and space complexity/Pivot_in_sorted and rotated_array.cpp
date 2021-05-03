#include<bits/stdc++.h>
using namespace std;

void findPivot(vector<int> &arr,int low,int high)
{
	int mid=low + (high-low)/2;
	if(arr[mid]<arr[mid+1] and arr[mid]<arr[mid-1])
	{
		cout<<arr[mid];
		return;
	}
	else if(arr[mid]>arr[low])
	{
		findPivot(arr,mid,high);
	}
	else
	{
		findPivot(arr,low,mid-1);
	}
}

void solve()
{
	int n;	
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	findPivot(arr,0,arr.size()-1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}

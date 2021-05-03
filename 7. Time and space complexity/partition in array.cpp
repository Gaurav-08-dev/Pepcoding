#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) 
	{
	cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void swap(vector<int>&arr, int i, int j) {
cout<<"Swapping " << arr[i] << " and " << arr[j]<<"\n";
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}


void partition(vector<int> &arr,int pivot)
{
	int i=0,j=0,k=arr.size()-1;

	while(i<arr.size())
	{
		if(arr[i]>pivot)
		{
			i++;
		}
		else if(arr[i]<=pivot)
		{
			swap(arr,i,j);
			i++;
			j++;
		}
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

	int pivot;
	cin>>pivot;

	partition(arr,pivot);
	print(arr);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
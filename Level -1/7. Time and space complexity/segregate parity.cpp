#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	cout<<"Swapping index "<<i<<" and index " << j<<"\n";
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

void display(vector<int> &arr)
{
	cout<<"\n";
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<"\n";
	}
}

void solve(vector<int> &arr)
{

	int i=0,j=0;
	while(i!=arr.size())
	{
		if(arr[i]%2==0)
		{
			i++;
		}
		else
		{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

    solve(arr);
    display(arr);

}
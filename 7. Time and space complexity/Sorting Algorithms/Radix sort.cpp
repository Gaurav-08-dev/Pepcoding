#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr) 
{
	for (int i = 0; i < arr.size(); i++) {
	  cout<<arr[i]<<"\n";
	}
	cout<<"\n";
}

void countSort(vector<int> &arr, int exp) 
{
	// write code here

	vector<int> fmap(10,0);

	for(int i=0;i<arr.size();i++)
	{
		int index=(arr[i]/exp) % 10;
		fmap[index]++;
	}

	fmap[0]--;

	for(int i=1;i<fmap.size();i++)
	{
		fmap[i]+=fmap[i-1];

	}
	int narr[arr.size()];

	for(int i=arr.size()-1;i>=0;i--)
	{
	int val=(arr[i] / exp) % 10;
	int index=val;
	int pos=fmap[index];
	narr[pos]=arr[i];
	fmap[index]--;
	}

	for(int i=0;i<arr.size();i++)
	{
		arr[i]=narr[i];
	}

	cout<<"After sorting on "<< exp << " place -> ";
	print(arr);
}

void radixSort(vector<int> &arr) 
{
// write code here  

int max1=INT_MIN;

// Find minimum element

for(int i=0;i<arr.size();i++)
{
	if(arr[i]>max1)
	{
		max1=arr[i];
	}

}
	int exp=1;

	while(exp<=max1)
	{
		countSort(arr,exp);
		exp*=10;
	}

}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	int n;
	cin>>n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
	  	arr.push_back(temp);
	}
	radixSort(arr);
	print(arr);
}


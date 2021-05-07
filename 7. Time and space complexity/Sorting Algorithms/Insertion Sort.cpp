#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &arr); 



// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j) 
{
	// cout<<"Swapping "<<arr[i]<<" and "<< arr[j]<<"\n";
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}



void insertionSort(vector<int> &arr)
{
	int n=arr.size();
	for(int i=1;i<n;i++)
	{
		int j=i;
		while(j>0 && arr[j-1]>arr[j])
		{
			swap(arr,j,j-1);
			j--;
		}
		// print(arr);
		// cout<<"\n";
	}
}


void print(vector<int> &arr) 
{
	for (int i = 0; i < arr.size(); i++) 
	{
	  cout<<arr[i]<<" ";
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

    insertionSort(arr);
    print(arr);
}
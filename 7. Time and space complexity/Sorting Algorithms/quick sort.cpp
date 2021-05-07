#include<bits/stdc++.h>
using namespace std;




void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) 
	{
	cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void swap(vector<int>&arr, int i, int j)
{
	cout<<"Swapping " << arr[i] << " and " << arr[j]<<"\n";
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


int partition_index(vector<int> &arr,int pivot,int low,int high)
{
	cout<<"low -> "<<low<<"\n";
	cout<<"high -> "<<high<<"\n";
	cout<<"pivot -> "<<pivot<<"\n";
	int i=low,j=low;

	while(i<=high)
	{
		if(arr[i]<=pivot)
		{
			swap(arr,i,j);
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	cout<<"pivot index -> "<<j-1<<"\n";
	return j-1;
}


void quicksort(vector<int> &arr,int low,int high)
{
	if(low<=high)
	{
		int pivot=arr[high];
		int pivot_index=partition_index(arr, pivot,low,high);
		print(arr);
		quicksort(arr,low,pivot_index-1);
		quicksort(arr,pivot_index+1,high);
	}
}


// OPTIMIZED For space 

// void quicksort(vector<int> &arr,int low,int high)
// {
// 	while(low<=high)
// 	{
// 		int pivot=arr[high];
// 		int pivot_index=partition_index(arr, pivot,low,high);
// 		quicksort(arr,low,pivot_index-1);
// 		low=pivot_index+1;
// 		// quicksort(arr,pivot_index+1,high);
// 	}
// }



// further optimization

// void quicksort(vector<int> &arr,int low,int high)
// {
// 	while(low<=high)
// 	{
// 		int pivot=arr[high];
// 		int pivot_index=partition_index(arr, pivot,low,high);

// 		if(pivot_index-low<high-pivot_index+1)
// 		{
// 			quicksort(arr,low,pivot_index-1);
// 			low=pivot_index+1;
// 		}
// 		else
// 		{
// 			quicksort(arr,pivot_index+1,high);
// 			high=pivot_index-1;
// 		}
// 	}
// }

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
	quicksort(arr,0,arr.size()-1);	
	print(arr);
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
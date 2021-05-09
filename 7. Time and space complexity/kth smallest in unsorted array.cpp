#include<bits/stdc++.h>
using namespace std;



void swap(vector<int> &arr, int i , int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition_index(vector<int > &arr,int low, int high)
{
	int pivot=arr[high];
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

	return j-1;
}

int randomPartiotion(vector<int> &arr, int low,int high)
{
	int n=high - low  + 1;
	int pivot=rand() % n;
	// cout<<"pivot= "<<pivot<<"\n";
	swap(arr,low+pivot, high);
	return partition_index(arr, low, high);
}

int randomized_quick_Select(vector<int > &arr,int low,int high,int k)
{
	int n=high - low + 1;
	if(k>0 and k<=n)
	{
		int pos=randomPartiotion(arr,low,high);
		// cout<<"pos= "<<pos-low<<"\n";
		// cout<<"low= "<<low<<"\n";

		if(pos-low==k-1)
		{
			return arr[pos];
		}
		if(pos-low>k-1)
		{
			return randomized_quick_Select(arr,low,pos-1,k);
		}
		// cout<<"k= "<<k-pos+low-1<<"\n";
		// cout<<"low= "<<low<<"\n";

		return randomized_quick_Select(arr,pos+1,high,k-pos+low-1);
	}
	return -1;
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

	int k;
	cin>>k;


	cout<<randomized_quick_Select(arr,0,n-1,k)<<"\n";	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}

/* The idea is to randomly pick a pivot element. 
To implement randomized partition, we use a random 
function, rand() to generate index between l and r, 
swap the element at randomly generated index with the
last element, and finally call the standard partition
process which uses last element as pivot. */

// ALSO CALLED RANDOMIZED QUICK SELECT

// FOR Kth largest change the condition to arr[i]>=pivot at line 20 :
 








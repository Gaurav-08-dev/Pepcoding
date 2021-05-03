#include<bits/stdc++.h>
using namespace std;


int linearsearch(vector<int> &arr,int target)
{
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]==target)
		{
			return i;
		}
	}
	return -1;
}

bool binary_search_rec(vector<int> &arr,int low,int high,int target)
{
	bool res=false;
	if(low>high)
	{
		return res;
	}
	int mid=low + (high-low)/2;
	if(arr[mid]==target)
	{
		res=true;
	}
	else if(arr[mid]<target)
	{
		res=binary_search_rec(arr,mid+1,high,target);
	}
	else
	{
		res=binary_search_rec(arr,low,mid-1,target);
	}
	return res;
}

// return index
int binary_search_rec_index(vector<int> &arr,int low,int high,int target)
{
	
	if(low>high)
	{
		return -1;
	}
	int mid=low + (high-low)/2;
	int res=-1;
	if(arr[mid]==target)
	{
		return mid;
	}
	else if(arr[mid]<target)
	{
		return binary_search_rec_index(arr,mid+1,high,target);
	}
	else
	{
		return binary_search_rec_index(arr,low,mid-1,target);
	}
	return -1;
}

void solve()
{
	vector<int> arr={1,2,3,4,5,58,90};
	cout<<"Linear search: "<<linearsearch(arr,2)<<"\n";
	


	cout<<"Binary search recursive: ";
	if(binary_search_rec(arr,0,arr.size()-1,9))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}


	cout<<"\n"<<binary_search_rec_index(arr,0,arr.size()-1,78);

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
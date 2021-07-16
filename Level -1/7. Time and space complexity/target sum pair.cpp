#include<bits/stdc++.h>
using namespace std;



void target_sum_pair(vector<int> &arr,int target)
{
	sort(arr.begin(),arr.end());
	
	int low=0,high=arr.size()-1;

	while(low<high)
	{
		int sum=arr[low]+arr[high];
		if(sum==target)
		{
			cout<<arr[low]<<","<<arr[high]<<"\n";
			low++; high--;
		}
		else if(sum>target)
		{
			high--;
		}
		else	
		{
			low++;
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

	int target;
	cin>>target;
	target_sum_pair(arr,target);
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}
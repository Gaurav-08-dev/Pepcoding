#include<bits/stdc++.h>
using namespace std;



void sliding_maximum(vector<int> &arr, int k)
{
	
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

	int k; cin>>k;

	sliding_maximum(arr,k);

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
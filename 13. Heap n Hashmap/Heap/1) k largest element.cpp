#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	int arr[n];
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int k;
	cin>>k;
	
		 // 1. add k elemnts 
	for(int i=0;i<k;i++)
	{
		pq.push(arr[i]);
	}

	// 2. process remaining element

	for(int i=k;i<n;i++)
	{
		if(arr[i]>pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}

	while(!pq.empty())
	{
		cout<<pq.top()<<"\n";
		pq.pop();
	}

}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}	

	int k;
	cin>>k;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<k;i++)
	{
		pq.push(arr[i]);
	}

	for(int i=k;i<n;i++)
	{
		pq.push(arr[i]);
		cout<<pq.top()<<"\n";
		pq.pop();
	}
	
	while(!pq.empty())
	{
	    cout<<pq.top()<<"\n";
	    pq.pop();
	}

}


int main(){

 
    solve();

}
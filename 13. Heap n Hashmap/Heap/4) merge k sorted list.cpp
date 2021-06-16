#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ss second
#define ff first

void solve()
{
	int k;
	cin>>k;

	vector<vector<int>> arr(k);

	// input
	for(int i=0;i<k;i++)
	{
		int size;
		cin>>size;

		arr[i]=vector<int>(size);
		for(int j=0;j<size;j++)
		{
			cin>>arr[i][j];
		}
	}


	vector<int> idx(k,0); // array no.

	priority_queue< pii, vector<pii>,greater<pii> > pq;

	for(int i=0;i<k;i++)
	{
		pii p;
		p.ff= arr[i][0];
		p.ss=i;
		pq.push(p);
	}

	vector<int> ans;

	while(!pq.empty())
	{
		pii x=pq.top(); //retrieving smallest pair
		pq.pop();

		ans.push_back(x.ff); // pushing the smallest value to answer vector

		if(idx[x.ss]+1 < arr[x.ss].size()) // checking if we are going out of bound
		{
			pii p;
			p.ff = arr[x.ss][idx[x.ss]+1];
			p.ss = x.ss;
			pq.push(p);
		}

		idx[x.ss]+=1;
	} 

	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
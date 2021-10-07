#include<bits/stdc++.h>
using namespace std;


int main()
{


		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		
	int n; //no. of soldiers
	cin>>n;

	vector<int> p; //power of each soldier
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		p.push_back(a);
		cout<<p[i];
	}

	int q; //no. of rounds
	cin>>q;

	int B_power[q]; // bishu power in each round
	for(int i=0;i<q;i++)
	{
		cin>>B_power[i];
	}

	sort(p.begin(),p.end());

	for(int i=0;i<q;i++)
	{
		cout<<upper_bound(p.begin(),p.end(),B_power[i])-p.begin()<<endl;
	}


}
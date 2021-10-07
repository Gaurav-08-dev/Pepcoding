#include<bits/stdc++.h>
using namespace std;

int main()
{
    
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	


int x,y;
cin>>x>>y;

	vector<vector<int>> A;

	for(int i=0;i<x;i++)
	{
		vector<int>temp;
		for(int j=0;j<y;j++)
		{
			int a;
			cin>>a;			
			temp.push_back(a);
		}
		A.push_back(temp);
	}

	int n,m;
	cin>>n>>m;

	vector<vector<int>> B;

	for(int i=0;i<x;i++)
	{
		vector<int>temp;
		for(int j=0;j<y;j++)
		{
			int a;
			cin>>a;			
			temp.push_back(a);
	}
		B.push_back(temp);
	}


	





}

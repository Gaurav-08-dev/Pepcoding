#include<bits/stdc++.h>
using namespace std;



void hamiltonian(int n,vector<pair<int,int>> graph[],int src,int osrc,unordered_set<int> &hashSet,string psf)
{
	if(hashSet.size()==n-1)
	{
		psf+=to_string(src);
		cout<<psf;;
		bool isCyclic=false;

		for(auto it: graph[osrc])
		{
			if(it.first==src)
			{
				isCyclic=true;
				break;
			}
		}

		if(isCyclic==true)
		{
			cout<<"*"<<"\n";
		}
		else
		{
			cout<<"."<<"\n";
		}
		return;
	}



	hashSet.insert(src);
	for(auto it: graph[src])
	{
		int nbr=it.first;

		if(hashSet.find(nbr)==hashSet.end())
		{
			hamiltonian(n,graph,nbr,osrc,hashSet,psf+to_string(src));
		}
	}

	hashSet.erase(src);
}

void solve()
{
	int n;  // no. of nodes
	int m; // no. of edges

	cin>>n>>m;

	vector<pair<int,int>> graph[n];
	for(int i=0;i<m;i++)
	{
		int u,v, wt;
		cin>>u>>v>>wt;

		graph[u].push_back(make_pair(v,wt));
		graph[v].push_back(make_pair(u,wt));
	}

	int src;
	cin>>src;

	unordered_set<int> hashSet(n);
	hamiltonian(n,graph,src,src,hashSet,"");

	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}
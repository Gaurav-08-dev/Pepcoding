#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,string>

string spath;
int spathwt=INT_MAX;
string lpath;
int lpathwt=INT_MIN;
string cpath;
int cpathwt=INT_MAX;
string fpath;
int fpathwt=INT_MIN;
priority_queue<pii, vector<pii>, greater<pii>> pq;


void multiSolver(vector<pair<int,int>> graph[],int src,int dest,vector<bool> &visited,int criteria,int k,string psf, int wsf)
{

	if(src==dest)
	{

		// smallest path

		if(wsf < spathwt)
		{
			spath=psf;
			spathwt=wsf;
		}

		// Largest path

		if(wsf > lpathwt)
		{
			lpath=psf;
			lpathwt=wsf;
		}

		// ceil path using factor

		if(wsf > criteria)
		{
			if(wsf < cpathwt)
			{
				cpath=psf;
				cpathwt=wsf;
			}
		}

		// floor path using factor

		if(wsf < criteria)
		{
			if(fpathwt < wsf)
			{
				fpathwt=wsf;
				fpath=psf;
			}
		}

		// Kth largest uisng min priority queue

		if(pq.size()<k)
		{
			pq.push({wsf,psf});
		}
		else
		{
			if(pq.top().first < wsf)
			{
				pq.pop();
				pq.push({wsf,psf});
			}
		}


		return;
	}
	visited[src]=true;

	for(auto it: graph[src])
	{
		int nbr=it.first;
		int wt=it.second;

		if(visited[nbr] == false)
		{
			multiSolver(graph,nbr,dest,visited,criteria,k,psf + to_string(nbr),wsf+wt);
		}

	}

	visited[src]=false;

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

	int src,dest;
	cin>>src>>dest;

	int criteria;
	cin>>criteria;

	int k;
	cin>>k;

	vector<bool> visited(n);
	// 	for(int i=0;i<n;i++)
	// {
	// 	cout<<"Node " <<i<<" makes edge with "<<"\n";


	// 	for(auto it=graph[i].begin();it!=graph[i].end();it++)
	// 	{
	// 		cout<<"\t"<<it->first<<" with edge weight of "<<it->second<<"\n";
	// 	}

	// 		cout<<"\n";
	// }

	multiSolver(graph,src,dest,visited,criteria,k,to_string(src) + "",0);

	cout<<"Smallest Path = "<<spath<<"@"<<spathwt<<"\n";
	cout<<"Largest Path = "<<lpath<<"@"<<lpathwt<<"\n";
	cout<<"Just Larger Path than "<<criteria<<" = "<<cpath<<"@"<<cpathwt<<"\n";
	cout<<"Just Smaller Path than "<<criteria<<" = "<<fpath<<"@"<<fpathwt<<"\n";
	cout<<k<<"th largest path = "<<pq.top().second<<"@"<<pq.top().first<<"\n";





}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
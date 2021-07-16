#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define tii pair<int,pair<int,int>>

// wt parent src
void min_wire(vector<pii> graph[],int n)
{
	priority_queue<tii, vector<tii>,greater<tii>> pq;

	pq.push({0,{-1,0}});

	vector<pii> mst[n];
	vector<bool> visited(n);

	while(!pq.empty())
	{
		tii rem=pq.top();
		pq.pop();

		if(visited[rem.second.second]==true)
		{
			continue;
		}

		visited[rem.second.second]=true;

		// work ->add edge

		if(rem.second.first!=-1){
			cout<<"["<<rem.second.second<<"-"<<rem.second.first<<"@"<<rem.first<<"]"<<"\n";
			mst[rem.second.second].push_back({rem.second.first,rem.first});
			mst[rem.second.first].push_back({rem.second.second,rem.first});

		}

		for(auto it: graph[rem.second.second])
		{
			if(visited[it.first]==false)
			{
				pq.push({it.second,{rem.second.second,it.first}});
			}
		}
	}



	// for(int i=0;i<n;i++)
	// {
	// 	cout<<"Node " <<i<<" makes edge with "<<"\n";


	// 	for(auto it=mst[i].begin();it!=mst[i].end();it++)
	// 	{
	// 		cout<<"\t"<<it->first<<" with edge weight of "<<it->second<<"\n";
	// 	}

	// 		cout<<"\n";
	// }

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

	min_wire(graph,n);	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
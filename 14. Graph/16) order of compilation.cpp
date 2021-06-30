#include<bits/stdc++.h>
using namespace std;

//  use of topological sort


void t_sort(vector<int> graph[],vector<bool> &visited,int src,stack<int> &s)
{
	visited[src]=true;
	for(auto it:graph[src])
	{
		if(visited[it]==false)
		{
			t_sort(graph,visited,it,s);
		}
	}
	s.push(src);
}
void order_of_compilation(vector<int> graph[],int n)
{	
	vector<bool> visited(n);
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			t_sort(graph,visited,i,s);
		}
	}

	while(!s.empty())
	{
		cout<<s.top()<<"\n";
		s.pop();
	}
}

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<int> graph[n];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	order_of_compilation(graph,n);	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
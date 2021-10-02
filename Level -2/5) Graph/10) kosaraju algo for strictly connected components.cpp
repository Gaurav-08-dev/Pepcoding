#include<bits/stdc++.h>
using namespace std;


void dfs(int node,stack<int> &st,vector<bool> &visited,vector<int> graph[])
{
	visited[node]=true;
	for(auto it: graph[node])
	{
		if(!visited[it])
		{
			dfs(it,st,visited,graph);
		}
	}

	st.push(node);
}
void revDFS(int node,vector<bool> &visited,vector<int> transpose[])
{
// 	cout<<node<<" ";
	visited[node]=true;
	for(auto it: transpose[node])
	{
		if(!visited[it])
		{
			revDFS(it,visited,transpose);
		}
	}
}

int solve(vector<int> graph[], int n)
{
	stack<int> st;
	vector<bool> visited(n+1,false);
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i,st,visited,graph);
		}
	}

	vector<int> transpose[n+1];
	for(int i=1;i<=n;i++)
	{
		visited[i]=false;
		for(auto it:graph[i])
		{
			transpose[it].push_back(i);
		}
	}

	int count=0;
	while(!st.empty())
	{
		int node=st.top();st.pop();
		
			if(!visited[node]){
			    
				revDFS(node,visited,transpose);
				count++;
				// cout<<"\n";
			}
		
	}

	return count;

}
int main(){

	int n,m;
	cin>>n>>m;

	vector<int> graph[n+1];

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

   cout<<solve(graph,n);

}
#include<bits/stdc++.h>
using namespace std;

void gcc(vector<int> graph[],int src,vector<bool> &visited,vector<int> &comp)
{
	visited[src]=true;
	comp.push_back(src);

	for(auto nbr: graph[src])
	{
		if(visited[nbr]==false)
		{
			gcc(graph,nbr,visited,comp);
		}
	}
}


int perfectFr(vector<int> graph[],int n)
{
	vector<vector<int>> comps;
	vector<bool> visited(n);
	for(int v=0;v<n;v++)
	{
		if(visited[v]==false)
		{
			vector<int> comp;
			gcc(graph,v,visited,comp);
			comps.push_back(comp);
		}
	}

	// Method 1
	int count=0;
	/*for(int i=0;i<comps.size();i++)
	{
		int s1=comps[i].size();

		for(int j=i+1;j<comps.size();j++)
		{
			int s2=comps[j].size();
			count+=(s1 * s2);
		}
	}*/

	// Method 2

	int sum= comps[comps.size()-1].size();
	for(int i=comps.size()-2;i>=0;i--)
	{
		int s=comps[i].size();
		count+=sum*s;
		sum+=s;
	}

	return count;
}


void solve()
{
	int n; // no. of vertices
	cin>>n;

	int k; // no. of edges
	cin>>k;

	vector<int> graph[n];
	for(int i=0;i<k;i++)
	{
		int src,nbr;
		cin>>src>>nbr;
		graph[src].push_back(nbr);
		graph[nbr].push_back(src);
	}

	// no. of pairs of perfect friend
	cout<<perfectFr(graph,n);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
#include<bits/stdc++.h>
using namespace std;

// order of directions -> top left down right
int xdir[]={-1,0,1,0};
int ydir[]={0,-1,0,1};

void gccForIsland(vector<vector<int>> &graph,int i,int j)
{
	graph[i][j]=-1;

	for(int d=0;d<4;d++)
	{
		int r=i + xdir[d];
		int c=j + ydir[d];

		if(r >= 0 and r<graph.size() and c>=0 and c<graph[0].size() and graph[r][c]==0)
		{
		gccForIsland(graph,r,c);	
		}
	}

}

int noOfIslands(vector<vector<int>> &graph)
{
	int count=0;

	for(int i=0;i<graph.size();i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			if(graph[i][j]==0)
			{
				count++;
				gccForIsland(graph,i,j);
			}
		}
	}

	return count;
}

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph;

	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		graph.push_back(temp);
	}


	cout<<noOfIslands(graph);
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
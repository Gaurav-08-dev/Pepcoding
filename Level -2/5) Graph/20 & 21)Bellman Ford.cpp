#include<bits/stdc++.h>
using namespace std;



void solve()
{
	int N,m;
	cin>>N>>m;

	vector<vector<int>> edge(m,vector<int>(3,0));

	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		edge[i][0]=u-1;
		edge[i][1]=v-1;
		edge[i][2]=wt;
	}

	int infinite=INT_MAX;
	vector<int> dist(N,infinite);
	dist[0]=0;


	for(int i=0;i<N-1;i++)
	{
		for(vector<int> it:edge)
		{
		    int u= it[0];
    		int v= it[1];
	    	int wt= it[2];
			if(dist[u] + wt < dist[v] and dist[u]!=infinite){
				dist[v]=dist[u] + wt;
			}
		}
	}
		


			/******* DETECT NEGATIVE CYCLE ************/
			for(vector<int> it:edge)
			{
			    int u= it[0];
	    		int v= it[1];
		    	int wt= it[2];
				if(dist[u] + wt < dist[v])
				{
					flag=1;
					break;
				}
			}
			
			if(flag==1)
	    		cout<<flag;
			else{
			    cout<<flag;
			}

		for(int i=1;i<N;i++)
		{
			cout<<dist[i]<<" ";
		}


}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
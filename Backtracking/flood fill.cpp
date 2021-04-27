#include<bits/stdc++.h>

using namespace std;


vector<int> rdir={-1,0,1,0};
vector<int> cdir={-0,-1,0,1};
char moves[]={'t','l','d','r'};

void floodfill(vector<vector<int>> &maze,int sr,int sc,int n,int m,string asf)
{

	// cout<<asf<<"\n";
	if(sr==n and sc==m)
	{
		cout<<asf<<"\n";
		return;
	}

	maze[sr][sc]=1;

	for(int dir=0;dir<rdir.size();dir++)
	{
		int rr= sr + rdir[dir];
		int cc= sc + cdir[dir];
		char ch= moves[dir];
		// cout<<ch<<"\n";
		if(rr>=0 and cc>=0 and rr<=n and cc<=m and maze[rr][cc]!=1)
		{
			floodfill(maze,rr,cc,n,m, asf + ch);
		}
	}	

	maze[sr][sc]=0;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr;

    for (int i = 0; i < n; i++)
    {
    	vector<int> temp;
        for (int j = 0; j < m; j++)
        {
        	int t;
            cin >> t; 
            temp.push_back(t);
        }
        arr.push_back(temp);
    }

    floodfill(arr,0,0,n-1,m-1,"");  
}



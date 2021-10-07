#include<bits/stdc++.h>
using namespace std;

int find_union(int x, vector<int> &parent)
{
    if(x==parent[x])
    {
        return x;
        
    }
    
    return parent[x]=find_union(parent[x],parent);
}


void solve(vector<vector<int>> &positions,int n,int m,int k)
{
    vector<int> ans;
    vector<int> parent(n*m,-1);
    vector<int> rank(n*m);
	vector<vector<int>> matrix(n,vector<int>(m,0));
	int count=0;
	
	vector<vector<int>> dir={{1,0},{0,-1},{-1,0},{0,1}};
	
	for(int i=0;i<positions.size();i++)
	{
	    int row=positions[i][0];
	    int col=positions[i][1];
	    
	    int cellNo=row * n + col;
	    if(parent[cellNo]!=-1)
	    {
	        ans.push_back(count);
	        continue;
	    }
	    
	    parent[cellNo]=cellNo;
	    rank[cellNo]=1;
	    count++;
	    
	    for(auto d: dir)
	    {
	        int r=row + d[0];
	        int c=col + d[1];
	        int cell=r * n + c;
	        
	        if(r<0 or c<0 or r>=n or c>=m or parent[cell]==-1)
	        {
	            continue;
	        }
	        
	        int lx=find_union(cellNo,parent);
	        int ly=find_union(cell,parent);
	        
	        if(lx!=ly)
	        {
	            if(rank[lx] > rank[ly])
	            {
	                parent[ly]=lx;
	            }
	            else if(rank[lx] < rank[ly])
	            {
	                parent[lx]=ly;
	            }
	            else
	            {
	                parent[ly]=lx;
	                rank[lx]++;
	            }
	            count--;
	        }
	    }
	    ans.push_back(count);
	}
	
	cout<<"[";
	for(int i=0;i<ans.size();i++)
	{
	   // cout<<ans[i]<<" ";
	    if(i==ans.size()-1)
	    {
	    cout<<ans[i];
	    }
	    else
	    {
	        cout<<ans[i]<<", ";
	    }
	}
	 cout<<"]";
}

int main(){

int n,m,k;
cin>>n>>m>>k;

vector<vector<int>> positions;
while(k--)
{
    int u,v;
    cin>>u>>v;
    positions.push_back({u,v});
}

solve(positions,n,m,k);


}
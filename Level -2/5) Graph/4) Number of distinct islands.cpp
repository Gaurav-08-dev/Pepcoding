#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &island,int i, int j,vector<int> &xdir,vector<int> &ydir,string& str)
{
    island[i][j]=0;
   vector<char> dir = {'t', 'l', 'd', 'r'};

  for(int d=0;d<4;d++)
    {
        int row=i + xdir[d];
        int col=j + ydir[d];
        if(row >=0 and row < island.size() and col >=0 and col<island[0].size() and island[row][col]!=0)
        {
            str+=""+dir[d];
            dfs(island,row,col,xdir,ydir,str);
        }
    }
    str+='z';
}
int solve(vector<vector<int>> &island)
{
    set<string> s;
   vector<int> xdir={-1,0,1,0};
    vector<int> ydir={0,-1,0,1};
    
    for(int i=0;i<island.size();i++)
    {
        for(int j=0;j<island[0].size();j++){
            
            if(island[i][j]==1)
            {
                string str;
                str+='x';
                dfs(island,i,j,xdir,ydir,str);
                s.insert(str);
            }
        }
    }
    return s.size();
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> island;
    
    for(int i=0;i<n;i++)
    {
        vector<int> x;
        for(int j=0;j<m;j++)
        {
            int temp;
            cin>>temp;
            x.push_back(temp);
        }
        island.push_back(x);
    }
    
    cout<<solve(island);
}
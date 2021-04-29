#include<bits/stdc++.h>
using namespace std;



/*void solve()
{
	for(int rad=1;rad<=1;rad++)
	{
		for(int d=0;d<8;d++)
		{
			int rr=r +(rad*direc[d][0]);
			int cc=c +(rad*direc[d][1]);

				// cout<<"radius: "<<rad<<" -> row "<<rr<<" -> col "<<cc<<"\n";

			if(rr>=0 and rr<n and cc>=0 and cc<n)
			{
				cout<<"radius: "<<rad<<" -> row "<<rr<<" -> col "<<cc<<"\n";
			}
		}
	}
}

// direction matrix
vector<vector<int>> direc={
				{-2,1},
				{-1,2},
				{1 ,2},
				{2 ,1},
				{2 ,-1},
				{1 ,-2},
				{-1,-2},
				{-2,-1}
}; */





vector<int> xdir = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<int>  ydir = {1, 2, 2, 1, -1, -2, -2, -1};

void displayBoard(vector<vector<int>> &board,int n)
{
    for(int i=0;i<board.size();i++)
    {
        for (int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void knight(vector<vector<int>> &board,int n,int r, int c,int jsf)
{
	if(jsf==n*n)
	{	
		board[r][c]=jsf; 
		displayBoard(board,n);
		board[r][c]=0; 
		return;
	}

// 	board[r][c]=jsf; 
	for(int d=0;d<xdir.size();d++)
	{
		int rr= r + xdir[d];
		int cc= c + ydir[d];
		if(rr>=0 and rr<n and cc>=0 and cc<n and board[rr][cc]==0)
		{board[rr][cc]=jsf+1; 
			knight(board,n,rr,cc,jsf+1);
			board[rr][cc]=0;
		}
	}
// 	board[r][c]=0;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,r,c;
    cin>>n>>r>>c;
    vector<vector<int>> board(n,vector<int>(n,0));
    knight(board,n,r,c,1);
}
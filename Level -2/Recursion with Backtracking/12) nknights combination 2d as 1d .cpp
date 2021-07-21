#include<bits/stdc++.h>
using namespace std;

static int xdir[]={-2,-1,-1,-2};
static int ydir[]={1,2,-2,-1};

bool isSafeToPlace(vector<vector<int>> &board,int row,int col)
{
	for(int d=0;d<4;d++)
	{
		int r= row + xdir[d];
		int c= col + ydir[d];


		if(r>=0 and r<board.size() and c>=0 and c<board[0].size() and board[r][c]==1)
		{
			return false;
		}

	}
	return true;
}

void solve(int kpsf, int tk,vector<vector<int>> &board, int lcno)
{

	if(kpsf == tk)
	{
		for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[0].size();j++)
			{
				if(board[i][j]==1)
				{
				    cout<<"k\t";
				}
				else
				{
				    cout<<"-\t";
				}
			}
			cout<<"\n";
		}
		cout<<"\n";
		return;
	}
	for(int i=lcno+1;i<board.size() * board[0].size();i++)
	{
		int row= i / board.size();
		int col= i % board[0].size();


		if(board[row][col]==0 and isSafeToPlace(board,row,col))
		{
			board[row][col]=1;
			solve(kpsf+1,tk,board,i);
			board[row][col]=0;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> board(n,vector<int>(n));
	solve(0,n,board,-1);
}
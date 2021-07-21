#include<bits/stdc++.h>
using namespace std;

void perm(vector<vector<int>> &board,int qpsf, int tq,int i, int j)
{

	if(qpsf==tq)
	{
		for(int r=0;r<board.size();r++)
		{
			for(int c=0;c<board[0].size();c++)
			{
				if(board[r][c]==1)
				{
					cout<<"q\t";
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
	
	// travel in remaining column in current row
	for(int c=j+1;c<board[0].size();c++)
	{
		int r=i;
		// place 
		board[r][c]=1;

		perm(board,qpsf+1,tq,r,c);
		// unplace
		board[r][c]=0;
	}

	// travel in remaining rows and columns

	for(int r=i+1;r<board.size();r++)
	{
		for(int c=0;c<board[0].size();c++)
		{
			// place 
			board[r][c]=1;

			perm(board,qpsf+1,tq,r,c);
			// unplace
			board[r][c]=0;
		}
	}
}
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> board(n,vector<int>(n));
	perm(board,0,n,0,-1);	
}
int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}
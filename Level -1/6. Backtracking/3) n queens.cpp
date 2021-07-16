#include<bits/stdc++.h>
using namespace std;


// Direction array
// int rdir[]={-1,-1,0,1,1,1,0,-1};
// int cdir[]={0,1,1,1,0,-1,-1,-1};

/*int direc[][2]={
			   {-1,0},
			   {-1,1},
			   {0,1},
			   {1,1},
			   {1,0},
			   {1,-1},
			   {0,-1},
			   {-1,-1}
};

int r=1,c=1; //current position
int n=10,m=10;
int radius=max(n,m);

void solve()
{
	for(int dir=0;dir<8;dir++)
	{
	for(int rad=1;rad<=radius;rad++)
	{

		int rr= r + (rad * direc[dir][0]);
		int cc= c + (rad * direc[dir][1]);

		if(rr>=0 and rr<n and cc>=0 and cc<m)
			{
				cout<<"Radius: "<<rad<<" Direction "<<dir<<" -> row "<<rr<<" -> col "<<cc<<"\n";
			}
	}
	}
}*/

bool isvalidtoplace(vector<vector<int>> &board,int sr,int sc)
{
	vector<vector<int>> direc={
			   {-1,0},
			   {-1,1},
			   {0,1},
			   {1,1},
			   {1,0},
			   {1,-1},
			   {0,-1},
			   {-1,-1}
	};

	int radius=board.size();
	for(int rad=1;rad<radius;rad++)
	{
		for(int dir=0;dir<direc.size();dir++)
		{
			int rr= sr + (rad * direc[dir][0]);
			int cc= sc + (rad * direc[dir][1]);

			if(rr>=0 and rr<radius and cc>=0 and cc<radius)
			{
				if(board[rr][cc]==1) 
					return false;
			}
		}
	}
	
	return true;
}

// qpsf -> queens placed so far
void nqueen(vector<vector<int>> &board,int sr,int sc,int qpsf,string asf)
{

	if(sr==board.size())
	{
		if(qpsf==board.size())
		{
			cout<<asf+"."<<"\n";	
		}
		return;
	}

	if(sc+1<board[0].size()) //next col is valid
	{
		if(isvalidtoplace(board,sr,sc)==true)
		{
			board[sr][sc]=1;
			nqueen(board,sr+1,0,qpsf+1,asf + to_string(sr) +"-"+ to_string(sc)+ ",");
			board[sr][sc]=0;
		}
		nqueen(board,sr,sc+1,qpsf,asf);

	}
	else
	{
		if(isvalidtoplace(board,sr,sc)==true)
		{
			board[sr][sc]=1;
			nqueen(board,sr+1,0,qpsf+1,asf + to_string(sr) +"-"+ to_string(sc)+ ",");
			board[sr][sc]=0;
		}
		nqueen(board,sr+1,0,qpsf,asf);
	}
}

// ALTERNATE APPROACH

void queen2(vector<vector<int>> &board,int row,string asf)
{

	if(row==board.size())
	{
		cout<<asf<<"\n";
		return;
	}

	for(int col=0;col<board.size();col++)
	{
		if(isvalidtoplace(board,row,col)==true)
		{
			board[row][col]=1;
			queen2(board,row+1,asf+ to_string(row) + "-" + to_string(col) + ", ");
			board[row][col]=0;
		}
	}
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // solve();
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    queen2(board,0,"");

}
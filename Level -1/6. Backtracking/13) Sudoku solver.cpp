#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<char>> &board,int row, int col,char c)
{
	for(int i=0;i<9;i++)
	{
		if(board[row][i]==c)
			return false;

		if(board[i][col]==c)
			return false;

		if(board[3 * (row/3) + i/3][3 * (col/3) + i%3]==c)
			return false;
	}

	return false;
}

bool solve(vector<vector<char>> &board) 
{
	for(int row=0;row<board.size();row++)
	{
		for(int col=0;col<board[0].size();col++)
		{
			if(board[row][col]=='.')
			{
				for(char c='1';c<='9';c++)
				{
					if(isvalid(board,row,col,c))
					{
						board[row][col]=c;
						if(solve(board)==true)
						{
							return true;
						}
						else
						{
							board[row][col]='.';
						}
					}
				}
				return false;
			}
		}
	}

	return true;
}


int main()
{
	
}
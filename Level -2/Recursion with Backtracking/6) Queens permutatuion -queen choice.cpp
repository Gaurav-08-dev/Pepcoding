#include<bits/stdc++.h>
using namespace std;




void solve(int tq, int qpsf,vector<vector<int>> &board)
{
    if(qpsf == tq)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!=0)
                {
                    cout<<"q"<<board[i][j]<<"\t";
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
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]==0)
            {
                // place queen
                board[i][j]=qpsf + 1;
                
                solve(tq,qpsf+1,board);
                
                // unplace queen
                board[i][j]=0;
                
            }
        }
    }
    
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n));
    solve(n,0,board);
}
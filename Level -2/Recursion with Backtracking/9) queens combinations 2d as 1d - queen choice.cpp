#include<bits/stdc++.h>
using namespace std;

// lcno -> last cell no.
void solve(vector<vector<int>> &board, int qpsf, int tq, int lcno)
{
    if(qpsf == tq)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"q"<<"\t";
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
    
    for(int b=lcno+1;b<board.size()*board[0].size();b++)
    {
        int r=b / board.size();
        int c=b % board[0].size();
        
        // place
        board[r][c]=1;
        
        solve(board,qpsf + 1,tq,b);
        
        // unplace
        board[r][c]=0;
    }
}
int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> board(n,vector<int>(n));
    solve(board,0,n,-1);
}

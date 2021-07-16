#include<bits/stdc++.h>
using namespace std;


bool check(vector<vector<char>>& board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)
        {
            return false;
        }
        if(board[row][i]==c)
        {
            return false;
        }
        if(board[3 * (row/3) + (i/3)][3 * (col/3)+ (i%3)]==c)
        {
            return false;
        }
        
    }
    return true;
}

bool check1(vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(char cn='1';cn<='9';cn++)
                {
                    if(check(board,i,j,cn))
                    {
                        board[i][j]=cn;
                    
                    
                    if(check1(board)==true)
                        return true;
                    else
                       board[i][j]='.';
                }
            }
            return false;
            }
        }
    }
    return true;
}

void solve()
{
    vector<vector<char>> board;
    for(int i=0;i<9;i++)
    {
        vector<char> temp;
        for(int j=0;j<9;j++)
        {
            char ch;
            cin>>ch;
            temp.push_back(ch);
        }
        board.push_back(temp);
    }

    check1(board);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
       #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 

    
    
    solve();

}

#include<bits/stdc++.h>
using namespace std;
#define MAX_ROWS 3
#define MAX_COLS 3

void solve()
{
	   int A[MAX_ROWS][MAX_ROWS];
	   int B[MAX_ROWS][MAX_ROWS];
	   int C[MAX_ROWS][MAX_ROWS];


    int row, col, sum = 0;
    

    for(row=0; row<MAX_ROWS; row++)
    {
        for(col=0; col<MAX_COLS; col++)
        {
            cin>>A[row][col];
        }
    }

     for(row=0; row<MAX_ROWS; row++)
    {
        for(col=0; col<MAX_COLS; col++)
        {
            cin>>B[row][col];
        }
    }


       for(row=0; row<MAX_ROWS; row++)
    {
        for(col=0; col<MAX_COLS; col++)
        {
        	C[row][col]=0;
        	if(row+col<MAX_ROWS)
        	{
        		C[row][col]=0;

        		for(int k=0;k<MAX_ROWS;k++)
        		{
        			C[row][col]+=A[row][k]* B[k][col];
        		}
        	}
        }
    }


         for(row=0; row<MAX_ROWS; row++)
    {
        for(col=0; col<MAX_COLS; col++)
        {
            cout<<C[row][col]<<" ";
        }

        cout<<"\n";
    }

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
#include<bits/stdc++.h>
using namespace std;

// tq -> total queens
void comb(int qpsf,int tq, int row, int col,string asf)
{
    if(row == tq)
    {
        if(qpsf==tq) 
        {
            cout<<asf<<"\n";
        }
        return;
    }
    
    if(col + 1 <tq)
    {
    // yes call
    if(qpsf<tq)
        comb(qpsf+1,tq,row,col+1,asf + "q");
    // no call
    comb(qpsf,tq,row,col+1,asf + "-");
    }
    else
    {
    // yes call
    if(qpsf < tq)
        comb(qpsf+1,tq,row+1,0,asf + "q\n");
    // no call
    comb(qpsf,tq,row+1,0,asf + "-\n");
    }
}
int main()
{
    int n;
    cin>>n;
    
    comb(0,n,0,0,"");
}
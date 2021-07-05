#include<bits/stdc++.h>
using namespace std;

// tabulation
int countSubsequence(string str)
{
    int aCount=0,bCount=0,cCount=0;
    
    for(int i=0;i<str.size();i++)
    {
        if(str.at(i)=='a')
        {
            aCount=2*aCount+1;
        }
        else if(str.at(i)=='b')
        {
            bCount=aCount + 2 * bCount;
        }
        else if(str.at(i)=='c')
        {
            cCount=bCount + 2 * cCount;
        }
    }
    
    return cCount;
}

void solve()
{
    string str;
    cin>>str;
    cout<<countSubsequence(str);
}

int main()
{
    solve();
}
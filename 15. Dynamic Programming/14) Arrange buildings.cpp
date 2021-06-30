#include<bits/stdc++.h>
using namespace std;


// recursion 
long build_rec(int n,int lastAdded)
{
    // space -> 0
    // buildings -> 1
    if(n==0) return 1;
    long count=0;
    
    if(lastAdded==0)
    {
        count+=build_rec(n-1,1);
    }
    count+=build_rec(n-1,0);
    
    return count;
}


long build_tab(int n)
{
    long building=1;
    long space=1;
    
    for(int i=2;i<=n;i++)
    {
        long n_building=space;
        long n_space=building+space;
        
        space=n_space;
        building=n_building;
    }
    
    long res=space + building;
    
    return res*res;
    
}


int main()
{
    int n;cin>>n;
    
    cout<<build_tab(n);
}
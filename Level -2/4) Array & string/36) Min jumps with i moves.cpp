#include<bits/stdc++.h>
using namespace std;
int solve(int target)
{
        target=abs(target);
        
        int jump=0,s=0;
        
        while(s<target)
        {
            jump++;
            
            s+=jump;
        }
        
        
        if(s==target)
        {
            return jump;
        }
        else if((s-target)%2==0)
        {
            return jump;
        }
        else if((s + jump + 1 - target )%2==0)
        {
            return jump+1;
        }
        else
        {
            return jump+2;
        }
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n);

}
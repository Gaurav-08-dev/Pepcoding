#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int row=pow(2,n);
    
    for(int i=0;i<row;i++) //convert i to binary and use 0s & 1s to print no.
    {
        int temp=i;
        string ans="";
        for(int j=n-1;j>=0;j--)
        {
            
            int rem=temp%2;
            temp/=2;
            
            if(rem==0)
            {
                ans="-	" + ans;
            }
            else
            {
                ans=to_string(a[j]) + "	" + ans;
            }
        }
        cout<<ans<<" ";
        
    }
}
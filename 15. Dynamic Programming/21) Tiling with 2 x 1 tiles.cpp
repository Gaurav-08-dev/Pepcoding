#include<bits/stdc++.h>
using namespace std;

int paint(int n)
{
    int a=1;
    int b=2;
    
    for(int i=1;i<n;i++)
    {
        int c=a + b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<paint(n);
}
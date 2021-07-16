#include<bits/stdc++.h>
using namespace std;

#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>

pq left; // max element on priority
mpq right; // min element on priority
    

void add(int val)
{
    if(right.size()>0 and right.top()< val)
    {
        right.push(val);
    }
    else
    {
        left.push(val);
    }

    // difference management

    if(left.size() - right.size() == 2)
    {
        right.push(left.top());
        left.pop();
    }
    else if(right.size() - left.size() == 2)
    {
        left.push(right.top());
        right.pop();
    }

}

int remove()
{
    if(left.size() + right.size() == 0)
    {
        return -1;
    }
    else if(right.size() > left.size())
    {
        int data=right.top();
        right.pop();
    }
    else
    {
        int data=left.top();
        left.pop();
    }
}


int peek()
{
    if(this.size()==0)
    {
        return -1;
    }
    else if(right.size() > left.size())
    {
        return right.top();
    }
    else
    {
        return left.top();
    }
}

int size()
{
    return right.size() + left.size();
}


void solve()
{

}
 
int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    solve();

}   
#include<bits/stdc++.h>
using namespace std;


bool duplicates(string str)
{
	
    stack<char> Stack;

    for (char ch: str)
    {
       	if (ch !=')')
        {
            Stack.push(ch);
        }
        else
        {
        	if(Stack.top()=='(')
        	{
				return true;
	       	}
	       	else
	       	{
	            while (Stack.top() != '(')
	            {
	                Stack.pop();
	            }
	            Stack.pop();  
        	}
        }
    }
    return false;
        
}

void solve()
{

	string str;
	getline(cin,str);

	if(duplicates(str))
		{cout<<"true"<<"\n";}

	else
		{cout<<"false"<<"\n";}

}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
}
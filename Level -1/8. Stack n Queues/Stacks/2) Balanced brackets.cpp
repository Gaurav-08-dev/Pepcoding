#include<bits/stdc++.h>
using namespace std;

/*bool match_brackets(stack<char> &s,char ch)
{
	if( s.top()!=ch)
	{
		return false;		
	}
	else if (s.empty())
	{
		return false;
	}
	else 
	{
		s.pop();
		return true;
	}
}*/

bool balancedbrackets(string str)
{
	stack<char> s;

	for(char ch: str)
	{
		if(ch =='(' or ch =='[' or ch =='{')
		{
			s.push(ch);
		}
		else if( ch ==')' )
		{
			if(s.empty())
			{
				return false;		
			}
			else if ( s.top()!='(')
			{
				return false;
			}
			else 
			{
				s.pop();
			}
		}
		else if(ch ==']')
		{	
			if(s.empty())
			{
				return false;		
			}
			else if ( s.top()!='[')
			{
				return false;
			}
			else 
			{
				s.pop();
			}
		}
		else if(ch=='}' )
		{	
			if(s.empty())
			{
				return false;		
			}
			else if ( s.top()!='{')
			{
				return false;
			}
			else 
			{
				s.pop();
			}
		}
	}

	if(s.empty())
	{
		return true;
	}
		return false;
}

void solve()
{
	string str;
	getline(cin,str);

	if(balancedbrackets(str))
	{
		cout<<"true"<<"\n";
	}
	else
	{
		cout<<"false"<<"\n";
	}
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
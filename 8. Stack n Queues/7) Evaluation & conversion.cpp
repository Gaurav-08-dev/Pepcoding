#include<bits/stdc++.h>
using namespace std;


int priority(char op)
{
	if(op=='/' or op=='*')
	{
		return 2;
	}
	else if(op=='+' or op=='-')
	{
		return 1;
	}
	else return 0;
}

int evaluate(int val1,int val2,char op)
{
	if(op=='*')
	{
		return val1*val2;
	}
	else if(op=='/')
	{
		return val1/val2;
	}
	else if(op=='+')
	{
		return val1+val2;
	}
	else if(op=='-')
	{
		return val1-val2;
	}
	else 
	{
		return 0;
	}
}

// INFIX Evaluationa and conversion
int infix_evaluation(string str)
{
	stack<char> op; //operator stack
	stack<int> vstack;  //value stack


	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		if(ch==' ')
		{
			continue;
		}
		else if(ch>='0' and ch<='9')
		{
			vstack.push(int(ch-'0'));
		}
		else if(ch=='(')
		{
			op.push(ch);
		}
		else if(ch==')')
		{
			while(op.top()!='(')
			{
				int val2=vstack.top();
				vstack.pop();
				int val1=vstack.top();
				vstack.pop();

				char ch=op.top();
				op.pop();

				int res=evaluate(val1,val2,ch);
				vstack.push(res);
			}
			op.pop();
		}
		else 
		{
			// Solve equal priority now, otherwise after loop we iterate in it with right to the left direction
			// because of behaviour of stack :
			while(op.size()>0 and vstack.top()!='(' and priority(op.top())>=priority(ch))
			{
				int val2=vstack.top();
				vstack.pop();
				int val1=vstack.top();
				vstack.pop();
				
				char ch=op.top();
				op.pop();
				

				int res=evaluate(val1,val2,ch);
				vstack.push(res);
			}

			op.push(ch);
		}
	}

	// some element may be present in stack
	while(op.size()>0)
	{
		int val2=vstack.top();
		vstack.pop();
		int val1=vstack.top();
		vstack.pop();
		
		char ch=op.top();
		op.pop();
				

		int res=evaluate(val1,val2,ch);
		vstack.push(res);
	}

	int ans=vstack.top();
	return ans;
}

void infix_postfix(string str)
{
	stack<char> op; //operator stack
	stack<string> vstack;  //value stack
	
	for(int i=0;i<str.size();i++)
	{
		char ch=str[i];
		if(ch==' ')
		{
			continue;
		}
		else if(ch>='a' and ch<='z')
		{
			string result;
			result+=ch;
			vstack.push(result);
			// cout<<vstack.top()<<"\n";
		}
		else if(ch=='(')
		{
			op.push(ch);
		}
		else if(ch==')')
		{
			while(op.top()!='(')
			{
				string val2=vstack.top();
				vstack.pop();
				string val1=vstack.top();
				vstack.pop();

				char ch=op.top();
				op.pop();

				string ans=val1 + val2 + ch;
				vstack.push(ans);
			
			}
			op.pop();
		}


		else 
		{
			// Solve equal priority now, otherwise after loop we iterate in it with right to the left direction
			// because of behaviour of stack :
			while(op.size()>0 and op.top()!='(' and priority(op.top())>=priority(ch))
			{
				string val2=vstack.top();
				vstack.pop();
				string val1=vstack.top();
				vstack.pop();
				
				char ch=op.top();
				op.pop();
				

				string ans=val1 + val2 + ch;
				vstack.push(ans);
			}

			op.push(ch);
		}
	}


	while(op.size()>0)
	{
		string val2=vstack.top();
		vstack.pop();
		string val1=vstack.top();
		vstack.pop();
		
		char ch=op.top();
		op.pop();
				

		string ans=val1 +val2 + ch;
		vstack.push(ans);
	}

	 cout<<vstack.top()<<"\n";
}

void infix_prefix(string str)
{
	stack<char> op; //operator stack
	stack<string> vstack;  //value stack
	



	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		if(ch==' ')
		{
			continue;
		}
		else if(ch>='a' and ch<='z')
		{
			string result;
			result+=ch;
			vstack.push(result);
			// cout<<vstack.top()<<"\n";
		}
		else if(ch=='(')
		{
			op.push(ch);
		}
		else if(ch==')')
		{
			while(op.top()!='(')
			{
				string val2=vstack.top();
				vstack.pop();
				string val1=vstack.top();
				vstack.pop();

				char ch=op.top();
				op.pop();

				string ans=ch + val1 + val2;
				vstack.push(ans);
			
			}
			op.pop();
		}


		else 
		{
			// Solve equal priority now, otherwise after loop we iterate in it with right to the left direction
			// because of behaviour of stack :
			while(op.size()>0 and op.top()!='(' and priority(op.top())>=priority(ch))
			{
				string val2=vstack.top();
				vstack.pop();
				string val1=vstack.top();
				vstack.pop();
				
				char ch=op.top();
				op.pop();
				

				string ans=ch + val1 + val2;
				vstack.push(ans);
			}

			op.push(ch);
		}
	}


	while(op.size()>0)
	{
		string val2=vstack.top();
		vstack.pop();
		string val1=vstack.top();
		vstack.pop();
		
		char ch=op.top();
		op.pop();
				

		string ans=ch + val1 +val2;
		vstack.push(ans);
	}

	string ans=vstack.top();
	 cout<<ans<<"\n";
}


// Postfix Evaluationa and conversion
void postfix_eval(string str)
{
	stack<int> vstack;
	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(ch - '0');
		}
		else
		{
			int val2=vstack.top();
			vstack.pop();

			int val1=vstack.top();
			vstack.pop();

			int res=evaluate(val1,val2,ch);
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";
}

void postfix_infix(string str)
{
	stack<string> vstack;
	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(to_string(ch-'0'));
		}
		else
		{
			string val2=vstack.top();
			vstack.pop();

			string val1=vstack.top();
			vstack.pop();

			// int res=evaluate(val1,val2,ch);
			string res="(" + val1 + ch + val2 + ")";
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";
}


void postfix_prefix(string str)
{
	stack<string> vstack;
	for(int i=0;i<str.size();i++)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(to_string(ch-'0'));
		}
		else
		{
			string val2=vstack.top();
			vstack.pop();

			string val1=vstack.top();
			vstack.pop();

			// int res=evaluate(val1,val2,ch);
			string res=ch + val1 + val2;
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";
}


// Prefix Evaluationa and conversion
void prefix_eval(string str)
{
	stack<int> vstack;
	for(int i=str.size()-1;i>=0;i--)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(ch - '0');
		}
		else
		{
			int val1=vstack.top();
			vstack.pop();
			int val2=vstack.top();
			vstack.pop();



			int res=evaluate(val1,val2,ch);
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";
}


void prefix_infix(string str)
{
	stack<string> vstack;
	for(int i=str.size()-1;i>=0;i--)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(to_string(ch-'0'));
		}
		else
		{
			string val1=vstack.top();
			vstack.pop();
			string val2=vstack.top();
			vstack.pop();

			// int res=evaluate(val1,val2,ch);
			string res="(" + val1 + ch + val2 + ")";
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";

}

void prefix_postfix(string str)
{
	stack<string> vstack;
	for(int i=str.size()-1;i>=0;i--)
	{
		char ch=str.at(i);
		if(ch>='0' and ch<='9')
		{
			vstack.push(to_string(ch-'0'));
		}
		else
		{

			string val1=vstack.top();
			vstack.pop();
			string val2=vstack.top();
			vstack.pop();

			// int res=evaluate(val1,val2,ch);
			string res=val1 + val2 + ch;
			vstack.push(res);
		}
	}

	cout<<vstack.top()<<"\n";
}

void solve()
{
	string str;
	getline(cin,str);
	// cout<<str;

	// infix_evaluation(str);
	infix_postfix(str);
	infix_prefix(str);
	// postfix_eval(str);
	// postfix_infix(str);
	// postfix_prefix(str);	

	// prefix_eval(str);
	// prefix_infix( str);
	// prefix_postfix( str);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
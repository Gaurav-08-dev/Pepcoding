#include<bits/stdc++.h>
using namespace std;

int main()
{
 	string s="00123400";

	int n=s.length();

	bool stack=0;

	for(int i=n-1;i>=0;i--)
	{
		if(!stack)
		{	
			if(s[i]!='0')
			{
				cout<<s[i];
				stack=1;

			}

		}
		else
		{
			cout<<s[i];
		}


	}


}
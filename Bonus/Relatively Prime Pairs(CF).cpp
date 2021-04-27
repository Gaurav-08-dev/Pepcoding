#include<bits/stdc++.h>
using namespace std;


// 2 no.s with difference 1 are prime pairs


// What are relative prime no.s?
	// If the only common factor of two numbers a and b is 1, then a and b are relatively prime numbers.

// two consecutive no.s are co prime




int main()
{
	// long long l,r;
	// cin>>l>>r;
	// cout<<"YES"<<endl;
	// for(long long i=l;i<r+1;i+=2)
	// {
	// 	cout<<i<<" "<<i+1<<endl;
	// }

	// cout<<ceil(34.234*100)/100;

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





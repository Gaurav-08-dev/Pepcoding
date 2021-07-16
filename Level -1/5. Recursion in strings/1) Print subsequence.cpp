#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.size()==0)
	{
		cout<<ans<<"\n";
		return;
	}

	char ch= ques.at(0);
	string rstr=ques.substr(1);
	printSS(rstr,ans + ch);
	printSS(rstr,ans + "");
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
    string str;
    cin >> str;
    printSS(str, "");
}
#include <iostream>
using namespace std;



/* With return type */


vector<string> gss(string s){
    
    if(s.size()==0)
    {
        vector<string> ans;
        // ans.push_back("");
        return ans;
    }
    
    char ch=s.at(0);
    string rres=s.substr(1);
    vector<string> rans=gss(rres);
    cout<<rans<<"\n";
    
    vector<string> fans;
    for(auto str: rans)
    {
        fans.push_back(""+str);
    }
    for(auto str: rans)
    {
        fans.push_back(ch + str);
    }
    
    return fans;
}


/* without return type */

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
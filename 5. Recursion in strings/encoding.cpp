#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // write your code here

	// cout<<"-"<<asf<<"\n";
	if(str.size()==0)
	{
		cout<<asf<<"\n";
		return;
	}

	int ch=str.at(0) - '0';
    if(ch==0)
    {
    	return;
    }

    char ch1= (char)(ch + 'a' - 1);
    string rstr=str.substr(1);
    printEncoding(rstr,asf + ch1);
    cout<<"here"<<"\n";
    // cout<<str.size()<<"\n";
    if(str.size()>1)
    {
    	int n2=str.at(1)-'0';
    	int n=ch * 10 + n2;

    	// cout<<n<<"\n";
    	if(n<=26)
    	{
    		char ch2=(char)(n+'a'-1);
    		string roq2=str.substr(2);
    		printEncoding(roq2,asf+ch2);
    	}
    }
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    string str;
    cin>>str;
    printEncoding(str,"");
    
}
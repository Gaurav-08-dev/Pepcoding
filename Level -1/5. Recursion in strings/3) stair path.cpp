#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    // write your code here

	if(n<=0)
	{
		cout<<psf<<"\n";

		return;
	}
    for(int jump=1;jump<=3 and n-jump>=0;jump++)
    {
    	printStairPaths(n-jump,psf + to_string(jump));
    }
    
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    printStairPaths(n, "");
}
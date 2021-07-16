#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // write your code here
    

    if(sc==dc and sr==dr)
    {
    	cout<<psf<<"\n";
    	return;
    }

	for(int jumps=1;jumps+sc<=dc;jumps++)
	{
		printMazePaths(sr,sc+jumps,dr,dc, psf+ 'h' + to_string(jumps));
	}

	for(int jumps=1;jumps+sr<=dr;jumps++)
	{
		printMazePaths(sr+jumps,sc,dr,dc, psf+'v' + to_string(jumps));

	}

	for(int jumps=1;jumps+sr<=dr and jumps+sc<=dc;jumps++)
	{
		printMazePaths(sr+jumps,sc+jumps,dr,dc, psf+'d' + to_string(jumps));
	}

	
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n ;
    int m ;cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
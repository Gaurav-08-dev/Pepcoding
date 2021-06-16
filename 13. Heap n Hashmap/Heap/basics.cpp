#include<bits/stdc++.h>
using namespace std;


void display(priority_queue<int> gq)
{
	priority_queue<int> g=gq;

	while(!g.empty())
	{
		cout<<"\t "<<g.top();
		g.pop();
	}
	cout<<"\n";
}

void solve()
{

	priority_queue<int, vector<int>,greater<int>> mpq; // min-heap
	priority_queue<int> gquiz; // max - heap
	gquiz.push(10);	
	gquiz.push(30);	
	gquiz.push(20);	
	gquiz.push(5);		
	gquiz.push(1);
	display(gquiz);
	cout<<gquiz.top();

	// min-heap
	


}


int main(){

    solve();
}
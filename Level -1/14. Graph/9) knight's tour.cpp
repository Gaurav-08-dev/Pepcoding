#include<bits/stdc++.h>
using namespace std;



void knight(vector<vector<int>> &board)
{

}
void solve()
{
	int n;
	cin>>n;

	int row,col;
	cin>>row>>col;

	vector<vector<int>> board;

	for(int i=0;i<n;i++)
	{
		vector<int> temp;

		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		board.push_back(temp);
	}	
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
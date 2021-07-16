#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &arr)
{
	vector<int> rdir={0,1,0,-1};
	vector<int> cdir={1,0,-1,0};

	int m=arr.size(),n=arr[0].size();
	vector<vector<bool>> seen(m,vector<bool>(n,false));
	int r=0,c=0,di=0;

	vector<int>  ans;
	for(int i=0;i<m*n;i++)
	{
		// cout<<"di= "<<di<<"\n";
		// cout<<arr[r][c]<<"\n";
		ans.push_back(arr[r][c]);
		seen[r][c]=true;

		int nr=r + rdir[di];
		int nc=c + cdir[di];
		// cout<<"nr= "<<nr<<"\n"<<"nc= "<<nc<<"\n";
		if(nr>=0 and nr<m and nc>=0 and nc<n and !seen[nr][nc])
		{
			r=nr; c=nc;
		}
		else
		{
			di=(di+1)%4;
			r+=rdir[di];
			c+=cdir[di];
		}
	}

	return ans;
}

void print(vector<int> &arr)
{
	for(int i=0;i<arr.size();i++)
	{
		
			cout<<arr[i]<<" ";
	}
}

void solve()
{
	int n,m;	
	cin>>n>>m;

	vector<vector<int>> arr;
	for(int i=0;i<m;i++)
	{
		vector<int> temp;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		arr.push_back(temp);
	}

	cout<<"\n\n";

	vector<int> res=spiral(arr);

	print(res);

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
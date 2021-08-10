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

// normal approach
void nspiral(vector<vector<int>> &arr)
{
	int minc=0,minr=0, maxc=arr[0].size()-1, maxr=arr.size()-1;
	
	int size=arr.size() * arr[0].size();
	int count=0;

	while(count < size)
	{
		// left wall

		for(int i=minr;i<=maxr and count < size;i++)
		{
			cout<<arr[i][minc]<<"\n";
		}
		minc++;

		// bottom wall

		for(int i=minc;i<=maxc and count< size;i++)
		{
			cout<<arr[maxr][i]<<"\n";
		}
		maxr--;

		// right wall

		for(int i=maxr;i>=minr;i--)
		{
			cout<<arr[i][maxc]<<"\n";
		}
		maxc--;

		// top wall

		for(int i=maxc;i>=minc;i--)
		{
			cout<<arr[minr][i]<<"\n";
		}
		minr++;

	}
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
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<m;j++)
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
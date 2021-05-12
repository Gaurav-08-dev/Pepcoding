#include<bits/stdc++.h>
using namespace std;


	
void merge(vector<pair<int ,int >> &p)
{
	stack<pair<int,int>> sp; 
	sp.push(p[0]);
	for(int i=1;i<p.size();i++)
	{
		pair<int,int> p1=p[i];
		cout<<"stack "<<sp.top().first<< " "<< sp.top().second<<"\n";

		if(p1.first <=sp.top().second)
		{
		    if(p1.second>sp.top().second)
		    {
			    sp.top().second=p1.second;
		    }
		}
		else
		{
			sp.push(p1);
		}
	}

	stack<pair<int,int>> rsp; 

	while(sp.size()>0)
	{
		rsp.push(sp.top());
		sp.pop();
	}
	while(rsp.size()>0)
	{
		cout<<rsp.top().first<<" "<<rsp.top().second<<"\n";
		rsp.pop();
	}

}



void solve()
{
	int n;
	cin>>n;

	vector<pair<int ,int >> p;
	for(int i=0;i<n;i++)
	{
		int x;
		int y;
		cin>>x>>y;
		p.push_back(make_pair(x,y));
	}

	sort(p.begin(),p.end());
	merge(p);


	/*for(int i=0;i<n;i++)
	{
		cout<<p[i].first<<" "<<p[i].second<<"
";
	}*/
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
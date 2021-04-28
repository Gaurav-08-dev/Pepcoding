#include<bits/stdc++.h>
using namespace std;


// Dummy matrix
int n=5,m=4;

// Direction array
int rdir[]={-1,0,1,0};
int cdir[]={0,1,0,-1};

int r=1,c=1; //current position
int radius=max(n,m);


void valid_calls_direction_first()
{
	for(int dir=0;dir<4;dir++)
	{
		for(int rad=1;rad<=radius;rad++)
		{
			int rr=r + (rad * rdir[dir]);
			int cc=c + (rad * cdir[dir]);

			if(rr>=0 and rr<n and cc>=0 and cc<m)
			{
				cout<<"Radius: "<<rad<<" Direction "<<dir<<" -> row "<<rr<<" -> col "<<cc<<"\n";
			}
		}
	}
}

void radius_first()
{
	for(int rad=1;rad<=radius;rad++)
	{
		for(int dir=0;dir<4;dir++)
		{

			int rr=r + (rad * rdir[dir]);
			int cc=c + (rad * cdir[dir]);
			cout<<"radius: "<<rad<<" -> row "<<rr<<" -> col "<<cc<<"\n";
		}
	}	
}

void Direction_first()
{
	for(int dir=0;dir<4;dir++)
	{
		for(int rad=1;rad<=radius;rad++)
		{
			int rr=r + (rad * rdir[dir]);
			int cc=c + (rad * cdir[dir]);
			cout<<"Radius: "<<rad<<" Direction "<<dir<<" -> row "<<rr<<" -> col "<<cc<<"\n";
		}
	}
	
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // radius_first();
    cout<<"\n\n";
    // Direction_first();
    valid_calls_direction_first();

}
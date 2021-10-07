#include<bits/stdc++.h>
using namespace std;

int find_pos_infinite(vector<int> &a,int target)
{
	int start=0,end=1;
	while(target>a[end])
	{
		start=end;
		end*=2;
	}

	// now appy binary search after while loop end with new start and end

}

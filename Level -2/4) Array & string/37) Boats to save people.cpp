#include<bits/stdc++.h>
using namespace std;




int solve(vector<int>& people, int limit) {

	sort(people.begin(),people.end());
	int boatCount=0;
	int i=0,j=people.size()-1;

	while(i<=j){
	    
	    if(people[i]+people[j]<=limit){
	        boatCount++;
	        i++;j--;
	    }
	    else
	    {
	        boatCount++;
	        j--;
	    }
	}

	return boatCount;

}


int main()
{
	int n;
	cin>>n;

	vector<int> people;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		people.push_back(temp);
	}

	int limit;
	cin>>limit;
	cout<<solve(people,limit);

}
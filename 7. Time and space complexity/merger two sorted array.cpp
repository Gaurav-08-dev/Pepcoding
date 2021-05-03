#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
	vector<int> arr3;

	int i=0,j=0;
	while(i<A.size() and j<B.size())
	{

	    if(A[i] < B[j])
	    {
	    	arr3.push_back(A[i]);
	    	i++;
	    
	    }
	    else
	    {
	    	arr3.push_back(B[j]);
	    	j++;
	    }
	}
	
	while(i<A.size())
	{
	    arr3.push_back(A[i]);
	    i++;
	}
	while(j<B.size())
	{
	    arr3.push_back(B[j]);
	    j++;
	}

	return arr3;
}





// Tweaks
vector<int> mergeTwoSortedArrays2(vector<int> &A, vector<int> &B)
{
	vector<int> arr3;

	int i=0,j=0;
	while(i<A.size() or j<B.size())
	{
		
		int ival = i<A.size() ? A[i]: INT_MAX;
		int jval = j<B.size() ? B[j]: INT_MAX;

	    if(ival > jval)
	    {
	    	arr3.push_back(jval);
	    	j++;
	    }
	    else
	    {
	    	arr3.push_back(ival);
	    	i++;
	    }
	}

	return arr3;
}






void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays2(A, B);
    output(ans);
    return 0;
}
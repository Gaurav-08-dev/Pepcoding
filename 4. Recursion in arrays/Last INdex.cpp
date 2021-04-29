#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){

	if(idx==n)
	{
		return -1;
	}

	int index=lastIndex(arr,idx+1,x,n);



	if(index==-1 and arr[idx]==x)
	{
		return index=idx;
	}
	return index;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}
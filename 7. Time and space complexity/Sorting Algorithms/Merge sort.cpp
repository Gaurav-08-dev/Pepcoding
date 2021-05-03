#include<bits/stdc++.h>
using namespace std;


void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> MergeSort(vector<int> &arr,int low,int high)
{
	if(high==low)
	{
		vector<int> bres;
		bres.push_back(arr[low]);
		return bres;
	}

	int mid=low + (high-low)/2;
	vector<int> arr1=MergeSort(arr,low,mid);
	vector<int> arr2=MergeSort(arr,mid+1,high);
	vector<int> res=mergeTwoSortedArrays(arr1,arr2);

	return res;
}

void solve()
{
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

	vector<int> ans=MergeSort(arr,0,n-1);
	print(ans);


}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

}
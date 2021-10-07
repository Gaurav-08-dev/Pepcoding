// ROW AND COLUMNS ARE SORTED IN MATRIX



#include<bits/stdc++.h>
using namespace std;



int find_in_sorted_matrix(int a[4][4],int row, int column,int key)
{
	
	int i=0,j=column-1;

	while((i>=0 && i<=row-1) and (j>=0 && j<=column-1))
	{
		if(a[i][j]==key)
		{
			cout<<i<<" "<<j<<endl;
			return 1;
		}
		else if(a[i][j]<key)
		{
			i++;
		}
		else if(a[i][j]>key)
		{
			j--;
		}
	}

	return -1;
}

int main()
{
	int a[4][4] = { { 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 27, 29, 37, 48 },
                    { 32, 33, 39, 50 }  };

	cout<<find_in_sorted_matrix(a,4,4,39);
}
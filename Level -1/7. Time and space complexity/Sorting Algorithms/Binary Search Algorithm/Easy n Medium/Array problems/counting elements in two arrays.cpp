#include<bits/stdc++.h>

using namespace std;



int count_value(int arr2[],int start,int end,int target)
{

    int mid;
    while(start<=end)
    {
         mid=start + (end-start)/2;
        
       if(arr2[mid]<=target)
       {
       	start=mid+1;
       }
       else
       {
       	end=mid-1;
       }
    }
    
    return end;
}

void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
    vector<int> v;
    sort(arr2,arr2+n);
    int count=0;
    for(int i=0;i<m;i++)
    {
        count=count_value(arr2,0,n-1,arr1[i])+1;
        cout<<count<<endl;
        v.push_back(count);
    }
    

}

int main()
{
	int m = 6, n =6;
int arr1[] = {1,2,3,4,7,9};
int arr2[] = {0,1,2,1,1,4};

// 0 1 1 1 2 4
countEleLessThanOrEqual(arr1,arr2,m,n);


}
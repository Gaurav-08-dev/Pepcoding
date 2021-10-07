#include <bits/stdc++.h>
using namespace std;



int search(int arr[],int L,int target)
{
    //2 3 5 5 20 80
    sort(arr,arr+L);
    int start=0,end=L-1;
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        // cout<<arr[mid]<<endl;
        if(arr[mid]==target)
        {
            return 1;
        }
        else if(target>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }

return -1;

}

int check(int arr[],int L,int N)
{
    for(int i=0;i<L;i++)
    {
        if(search(arr,L,N+arr[i])==1)
        {
            return 1;
        }

    }
    
    return -1;
}

int main() {
	//code
	
	
	    int L=6,N=10;
	   
	    int arr[L]={5 ,20 ,3 ,2, 5,80};
	   
	    sort(arr,arr+L);
	   
	    
	    cout<<check(arr,L,N)<<endl;
	    
	    
	return 0;
}
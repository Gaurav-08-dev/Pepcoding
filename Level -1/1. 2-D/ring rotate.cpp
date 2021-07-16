#include<bits/stdc++.h>
using namespace std;

// 1. Select the shell
// 2. convert that shell into 1D array
// 3. rotate the array
// 4. put the rotated array back to matrix



// calculate 1d array size
int arraysize(int s,int n,int m)
{
	int minr=s-1,minc=s-1;
    int maxr=n-s,maxc=m-s;
    
    
    
    int array_size=2*(maxr - minr + maxc -minc);
    return array_size;
}


// DISPLAY
void display(int **arr,int n,int m)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

// void display1(int *arr,int s,int n,int m)
// {
// 	int n1=arraysize(s,n,m);
// 	for(int i=0;i<n1;i++)
// 	{
// 		cout<<arr[i]<<" ";

// 	}

// 	cout<<"\n\n\n";
// }


// extract 1d array from matrix
int* givearray(int **a,int s,int n,int m)
{
    // for every shell starting point -> (s-1,s-1) || ending point -> (n-s,m-s)
    
    int minr=s-1,minc=s-1;
    int maxr=n-s,maxc=m-s;
    
    
    // building 1d array out of matrix
    
    // int lw = maxr-minr+1;
    // int bw = maxc-maxc+1;
    int array_size=2*(maxr - minr + maxc -minc);
    // cout<<array_size<<"\n";
    int index=0;
    int* arr=new int[array_size];
    
    // left wall
    for(int i=minr;i<=maxr;i++)
    {
        arr[index]=a[i][minc];
        index++;
    }
    
    // bottom wall
    
    for(int i=minc+1;i<=maxc;i++)
    {
        arr[index]=a[maxr][i];
        index++;
    }
    
    // Right wall
    
    for(int i=maxr-1;i>=minr;i--)
    {
        arr[index]=a[i][maxc];
        index++;
    }
    
    // top wall
    
    for(int i=maxc-1;i>=minc+1;i--)
    {
        arr[index]=a[minr][i];
        index++;
    }

    // display1(arr,s,n,m);
    
    return arr;
}

void reverse(int* arr,int start,int end)
{
    int temp;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++; end--;
    }
}


void rotate(int *arr,int r,int s,int n1,int m)
{
    // optimising no. of rotation

    int n=arraysize(s,n1,m);

    // cout<<n<<"\n";
    r=r%n;
    
    if(r<0)
    {
        r+=n;
    }
    
    reverse(arr,0,n-r-1);
    reverse(arr,n-r,n-1);
    reverse(arr,0,n-1);
}



void fillshell(int** a,int s,int* arr,int n,int m)
{
	int minr=s-1,minc=s-1;
    int maxr=n-s,maxc=m-s;
    
    
    // building 1d array out of matrix
    
   
    
    int index=0;
    
    
    // left wall
    for(int i=minr;i<=maxr;i++)
    {
        a[i][minc]=arr[index];
        index++;
    }
    
    // bottom wall
    
    for(int i=minc+1;i<=maxc;i++)
    {
        a[maxr][i]=arr[index];
        index++;
    }
    
    // Right wall
    
    for(int i=maxr-1;i>=minr;i--)
    {
        a[i][maxc]=arr[index];
        index++;
    }
    
    // top wall
    
    for(int i=maxc-1;i>=minc+1;i--)
    {
        a[minr][i]=arr[index];
        index++;
    }
}

void rotateshell(int **a,int s,int r,int n,int m)
{
    int* arr= givearray(a,s, n, m);
    rotate(arr,r,s,n,m);
    fillshell(a,s,arr,n,m);
}






int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
    cin>>n>>m;
    
    
    // dynamically creating 2d array
    int **a= new int*[n];
    
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    int s,r;
    cin>>s>>r;

    // display(a,n,m);
    // cout<<"\n\n";
    
    rotateshell(a,s,r,n,m);
    display(a,n,m);
    delete a;
    
 }


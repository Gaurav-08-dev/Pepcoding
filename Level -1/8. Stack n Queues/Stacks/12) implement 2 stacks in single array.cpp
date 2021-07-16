#include<bits/stdc++.h>
using namespace std;



class stack1{
public:
int *data;
int tos1;
int tos2;
int size;

stack1(int size)
{
	data=new int[size];
	tos1=-1; tos2=size;
}

int size1()
{
	return tos1+1;
}
int size2()
{
	return size-tos2;
}

void push1(int val)
{
	if(tos1+1<tos2)
	{
		data[tos1+1]=val;
		tos1++;
	}
	else
	{
		cout<<"Overflow"<<"\n";
		return;
	}
}

void push2(int val)
{
	if(tos2-1>tos1)
	{
		data[tos2-1]=val;
		tos2--;
	}
	else
	{
		cout<<"Overflow"<<"\n";
		return;
	}
}

int pop1()
{
	if(tos1==-1)
	{
		cout<<"Underflow"<<"\n";
		return -1;
	}

	int x=data[tos1];
	tos1--;
	return x;
}


int pop2()
{
	if(tos2==size)
	{
		cout<<"Underflow"<<"\n";
		return -1;
	}

	int x=data[tos2];
	tos2++;
	return x;
}

};

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    stack1 s1(5);
    s1.push1(1);
    cout<<s1.pop1();

    
}
#include<bits/stdc++.h>
using namespace std;


class stack1{
public:
	int size;
	int *s;
	int top;

	stack1();
	void create(int size);
	void display();
	void push(int data);
	int pop();
	int peek(int pos);
	int stack_top();
	bool stack_empty();
};

stack1:: stack1()
{
	this->top=-1;
}

stack1:: create(int size)
{
	s=new int [size];
}

stack1::push(int data)
{
	if(top>=size-1)
	{
		cout<<"Overflow";
		exit(0);
	}
	else
	{
		top++;
		s[top]=data;
	}
}

stack1::pop()
{
	if(top==-1)
	{
		cout<<"Underflow";
		exit(0);
	}
	else
	{
		top--;
	}
}


int stack1::peek(int pos)
{
	if(pos<0 or pos >size-1)
	{
		cout<<"invalid position";
		exit(0);
	}
	else
	{
		return s[top-pos+1];
	}
}
void stack1::display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		cout<<s[i]<<endl;
	}
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    stack1 *st=new stack1();
	st->create(5);
	st->push(1);
	st->push(2);
	st->push(3);
	st->push(4);
	st->push(5);

	st->display();
	// cout<<endl;
	// st->pop();
	// cout<<st->peek(1);
	// cout<<st->stack_top();


}
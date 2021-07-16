#include<bits/stdc++.h>
 
using namespace std;


 
/* A simple stack class with
basic stack funtionalities */

class Stack {
private:
    static const int max=5;
    // int size;
    // int *s;
    int s[max];
    int top;

    int min=INT_MAX; //for O(1) extra space approach
 
public:
    Stack(){ this->top=-1; }
    // Stack(int size){this->top=-1;this->size=size;top=-1;s=new int[this->size];}

    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
    void display();
    int peek();
    int get_min();
};
 

 int Stack:: get_min()
 {
 	if(top==-1)
 	{
 		cout<<"Stack Underflow"<<"\n";
 		 		return -1;
 	}
 	return min;
 }
 bool Stack::isFull()
 {
    if(top==max-1)
    {
        return true;
    }
    return false;
 }

bool Stack:: isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}


 void Stack:: push(int x)
 {
    if(isFull())
    {
        cout<<"Stack Overflow"<<"\n";
        return;
    }

    if(min>x)
    {
    	top++;
    	s[top]=x + x -min;
    	min=x; 
    }
    else
    {
    	top++;
    	s[top]=x;
    }
 }

 int Stack:: pop()
 {
    if(top==-1)
    {
        cout<<"Stack Underflow"<<"\n";
        return -1;
    }
    if(s[top]<min)
    {
    	int ans=min;
        min=2 * ans - s[top];
        top--;
        return ans;
    }

    	int y=s[top];
    	top--;
    	return y;
    
 }

 int Stack::peek()
 {
    if(top<0)
    {
        cout<<"Stack Empty"<<"\n";
        return -1;
    }
    if(s[top]<min)
    {
    	return min;
    }
    
        return s[top];
    
 }

 void Stack:: display()
 {
    for(int i=top;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }
 }


class getmin : public Stack
 {
 	Stack min;

 public:

 	// getmin(int size){this->top=-1;this->size=size;top=-1;s=new int[this->size];}

 	int pop();
 	void push(int val);
 	int get_min();

 };


/* O(N) space approach */

/* void getmin:: push(int x)
{
	if(isEmpty())
	{
		Stack::push(x);
		min.push(x);
	}
	else
	{
		Stack::push(x);
		int y=min.pop();
		if(x<y)
		{
			min.push(x);
		}
		else
		{
			min.push(y);
		}
	}
}

int getmin::pop()
{
	int x=Stack::pop();
	min.pop();
	return x;
}

int getmin::get_min()
{
	int x=min.pop();
	min.push(x);
	return x;
}

*/



int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout<<s1.get_min();

}
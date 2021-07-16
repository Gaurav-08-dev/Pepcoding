#include<bits/stdc++.h>
 
using namespace std;


 
/* A simple stack class with
basic stack funtionalities */

class Stack {
private:
    static const int max=5;
    int size;
    int *s;
    // int s[max];
    int top;
 
public:
    Stack(){ this->top=-1; }
    Stack(int size){this->top=-1;this->size=size;top=-1;s=new int[this->size];}

    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
    void display();
    int peek();
};
 

 bool Stack::isFull()
 {
    if(top==size-1)
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

        top++;
        s[top]=x;
 }

 int Stack:: pop()
 {
    if(top==-1)
    {
        cout<<"Stack Underflow"<<"\n";
        return -1;
    }
    else
    {
        int y=s[top];
        top--;
        return y;
    }

 }

 int Stack::peek()
 {
    if(top<0)
    {
        cout<<"Stack Empty"<<"\n";
        return -1;
    }
    else
    {
        return s[top];
    }
 }

 void Stack:: display()
 {
    for(int i=top;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }
 }





int main()
{
    Stack s1(5);

    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.push(5);
    // s1.push(5);

    // s1.display();
}
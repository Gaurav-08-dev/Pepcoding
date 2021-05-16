#include<bits/stdc++.h>
using namespace std;

class circularQueue{

private:
	int size;
	int *data;
	int front;
	int rear;

public:

	circularQueue()
	{this->front=-1;
		this->rear=-1;
		data=new int[5];
	}
	circularQueue(int cap){this->front=-1;this->rear=-1;this->size=cap;data=new int[this->size];}
	void push_back(int val);
	int pop_front();
	void display();
	bool isempty();
	bool isfull();
	int peek();
};

bool circularQueue::isempty()
{
	if(front==-1)
	{
		return true;
	}
	return false;
}

bool circularQueue::isfull()
{
	if(rear==size-1)
	{
		return true;
	}
	return false;
}

void circularQueue::push_back(int val)
{
	if(isfull())
	{
		cout<<"queue full"<<"\n";
		return ;
	}
	if(isempty())
	{
		front++; rear++;
		data[rear]=val;
	}
	else
	{
		int indx=(rear+front+1)%size;
		data[indx]=val;
		rear++;
	}

}

int circularQueue:: pop_front()
{
	if(isempty())
	{
		cout<<"Queue Emtpy"<<"\n";
		return -1;
	}

	int ans=data[front];
	front=(front+1)%size;
	rear--;
	return ans;
}

void circularQueue:: display()
{
	for(int i=0;i<size;i++)
	{
		cout<<data[(front+i)%size]<<" ";
	}
	cout<<"\n";
}

int circularQueue:: peek()
{
	if(isempty())
	{
		cout<<"Underflow"<<"\n";
		return -1;
	}
	return data[front];
}
int main()
{
	circularQueue q(5);
	// cout<<q.peek()<<"\n";
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	q.push_back(5);
	cout<<q.peek()<<"\n";

	q.display();
	q.pop_front();
	q.push_back(6);
	q.display();



}
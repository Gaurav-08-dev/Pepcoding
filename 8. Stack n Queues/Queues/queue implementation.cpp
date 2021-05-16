#include<bits/stdc++.h>
using namespace std;


/* 

empty
size
front
back
push_back
pop_front

*/

// Initially front and rear are at the same position i.e. 0
// When value is pushed rear moves forward
// When value is removed front moves forward 


class Queue{

	private:
		int *data;
		int size;
		int front;
		int rear;
	
	public:
		Queue()
		{
			size=5;
			data=new int[size];
			this->front=-1;
			this->rear=-1;
		}
		Queue(int size)
		{
			this->size=size;
			data=new int[this->size];
			this->front=-1;
			this->rear=-1;
		}

		void push_back(int val);
		int pop_front();
		// int size();
		bool is_empty();
		void display();
		int peek();
};

		bool Queue::is_empty()
		{
			if(front==-1 and rear==-1)
			{
				return true;
			}
			return false;
		}

		void Queue::push_back(int val)
		{
			if(rear==size-1)
			{
				cout<<"Overflow"<<"\n";
				return ;
			}
			// int index=(this.front + this.rear) % data.size();
			if(is_empty())
			{
				rear++;
				front++;
				data[rear]=val;
			}
			else
			{
				rear++;
				data[rear]=val;
			}
	
		}


		int Queue::pop_front()
		{
			if(is_empty())
			{
				cout<<"Undertflow"<<"\n";
				return -1;
			}

			// front=(front + 1)%data.size();
			int x=data[rear];
			rear--;
			return x;
		}


		int Queue:: peek()
		{
			if(rear==0)
			{
				cout<<"Undertflow"<<"\n";
				return -1;
			}
			return data[front];
		}

		void Queue:: display()
		{
			for(int i=front+1;i<=rear;i++)
			{
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}



int main()
{

	Queue q(5);
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	q.push_back(5);
	q.display();
	q.pop_front();
	q.display();

}

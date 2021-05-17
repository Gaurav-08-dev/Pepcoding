#include<bits/stdc++.h>
using namespace std;

/*
class queue1{

public:
	list<int> l;

	queue1()
	{
		list<int> l;
	}


	int size()
	{
		return l.size();
	}

	void push(int val)
	{
		l.push_back(val);
	}

	void pop()
	{
		l.pop_front();
	}

	int top()
	{
		return l.front();
	}
};
*/

class node
{
	public:
		node* next;
		int data;
};

class linkedList
{

public:
	node *head,*last;
	int size;

	linkedList()
	{
		this->head=this->last=NULL;
		size=0;
	}

	void addFirst(int val)
	{
		size++;
		node* N=new node();
		N->data=val;
		N->next=NULL;

		if(head==NULL)
		{
			head=N;
			last=head;
		}
		else
		{
			N->next=head;
			head=N;
			last->next=NULL;
		}
	}

	void addLast(int val)
	{
		size++;
		node* N=new node();
		N->data=val;
		N->next=NULL;
		if(head==NULL)
		{
			head=N;
			last=head;
		}
		else
		{
			last->next=N;
			last=N;
		}

	}

	void addAt(int index,int val)
	{
		if(index<0 or index>size)
		{
			cout<<"Invalid"<<"\n";
			return;
		}
		else if(index==0)
		{
			addFirst(val);
		}
		else if(index==size)
		{
			addLast(val);
		}
		else
		{
			
			node* temp=head;
			for(int i=0;i<index-1;i++)
			{
				temp=temp->next;
			}
			node* N=new node();
			N->data=val;
			N->next=NULL;
			N->next=temp->next;
			temp->next=N;
			size++;
		}

	}

	int size1()
	{
		return size;
	}

	void display()
	{
		node* head=this->head;
		while(head)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
	}


	int getFirst()
	{
		node* head=this->head;
		if(!head)
		{
			return -1;
		}
		return head->data;
	}

	int getlast()
	{
		node* last=this->last;
		if(!last)
		{
			return -1;
		}
		return last->data;	
	}


	int getAt(int index)
	{
		if(index<0 or index>=size)
		{
			cout<<"Invalid Arguments"<<"\n";
			return -1;
		}
		if(size==0)
		{
			cout<<"List is empty"<<"\n";
			return -1;
		}
		node* t=head;
		for(int i=0;i<index;i++)
		{
			t=t->next;
		}

		return t->data;

	}







	void removeFirst()
	{
		if(size==0)
		{
			cout<<"List empty"<<"\n";
			return ;
		}

		head=head->next;
		size--;
	}

	void removeLast()
	{
		if(size==0)
		{
			cout<<"List empty"<<"\n";
			return ;
		}

		node* t=head;
		for(int i=0;i<size-2;i++)
		{
			t=t->next;
		}
		last=t;
		t->next=NULL;
		size--;
	}

	// int removeAt()
	// {}

};

int main()
{
	linkedList* q=new linkedList();

	q->addLast(1);
	q->addLast(2);
	q->removeFirst();
	cout<<q->getFirst();


}
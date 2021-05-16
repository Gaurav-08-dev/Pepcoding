#include<bits/stdc++.h>
using namespace std;


// Node structure
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


	void addAt(int val,int index)
	{
		
	}

	int getAt(int index)
	{

	}

	int removeFirst()
	{}

	int removeLast()
	{}

	int removeAt()
	{}

};

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    linkedList *ll=new linkedList();
    ll->addFirst(1);
    ll->addLast(12);
    ll->addLast(13);
    ll->addFirst(11);
    ll->display();
    cout<<"\n"<<ll->size1();
    cout<<"\n"<<ll->getFirst();
    cout<<"\n"<<ll->getlast();



}
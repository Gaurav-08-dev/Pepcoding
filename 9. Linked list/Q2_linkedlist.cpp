#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node* next;
    int data;
};

class ll
{
public:
    node *head,*last;

    ll(); //constructor
    ~ll(); //deconstructor
    void add(int data);
    void partition();
    void print();
};

ll::ll()
{
    this->head=NULL;
    last=head;
}

ll::~ll()
{
    cout<<"Deleted";
}

void ll::add(int val)
{
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

void ll::print()
{
    node* head=this->head;
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


void ll:: partition()
{
    /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    int x=head->data;
     node *smallerHead = NULL, *smallerLast = NULL;
     node *greaterLast = NULL, *greaterHead = NULL;
     node *equalHead = NULL, *equalLast = NULL;
 
    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while (head != NULL)
    {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
 
        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next  = head;
                greaterLast = head;
            }
        }
 
        head = head->next;
    }
 
    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;
 
    // Connect three lists
 
    // If smaller list is empty
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            {head=greaterHead;return;}
        equalLast->next = greaterHead;
        head=equalHead;
        return;
    }
 
    // If smaller list is not empty
    // and equal list is empty
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        head=smallerHead;
        return;
    }
 
    // If both smaller and equal list
    // are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    head=smallerHead;
    return;
}





int main()
{
    ll* list=new ll();
    // for(int i=0;i<10;++i)
    // {
    //     list->add(i);
    // }

    list->add(2);list->add(1);list->add(0);list->add(34);list->add(3);
    list->print();
    cout<<endl;
    list->partition();
    cout<<endl;
    list->print();
    delete list;
}

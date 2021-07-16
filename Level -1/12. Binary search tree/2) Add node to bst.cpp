#include<bits/stdc++.h>
using namespace std;


struct Node{
	
	public:
	
	int data;
	Node *left,*right;

	Node(int val)
	{
		data=val;
		left=right=NULL;
	}

	Node(int val, Node* left,Node* right)
	{
		data=val;
		this->left=left;
		this->right=right;
	}
};

Node* construct(int arr[],int lo,int hi)
{
	if(lo > hi) return NULL;

	int mid=lo + (hi-lo)/2;

	Node* nn=new Node(arr[mid]);

	nn->left=construct(arr,lo,mid-1);
	nn->right=construct(arr,mid+1,hi);

	return nn;
}

void display(Node* node)
{
	if(node==NULL) return;
	cout<<node->data<<" ";
	display(node->left);
	display(node->right);

}

Node* add_node(Node* root,int data)
{
	if(root==NULL)
	{
		Node* nn=new Node(data,NULL,NULL);
		return nn;
	}

	if(data > root->data)
	{
		root->right=add_node(root->right,data);
	}
	else if(data < root->data)
	{
		root->left=add_node(root->left,data);
	}

	return root;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
	
    int data[]={10,20,30,40,50,60,70,80,90};
    Node* root=construct(data,0,8);
    display(root);
    cout<<"\n";
    root=add_node(root,100);
    display(root);


}

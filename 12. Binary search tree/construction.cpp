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
		left=left;
		right=right;
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

int size(Node* root)
{
	if(root==NULL) return 0;

	int ls=size(root->left);
	int rs=size(root->right);

	int ts=ls + rs +1;

	return ts;

}

int sum(Node* root)
{
	if(root==NULL) return 0;

	int ls=sum(root->left);
	int rs=sum(root->right);

	 return ls + rs + root->data;
}

int height(Node* root)
{
	if(root==NULL)
	{
		return -1;
	}

	int lh=height(root->left);
	int rh=height(root->right);

	return max(lh,rh)+1;

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
    cout<<"Size: "<<size(root)<<"\n";
    cout<<"Sum: "<<sum(root)<<"\n"; 
    cout<<"Height: "<<height(root)<<"\n"; 


}
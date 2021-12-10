struct Node{
	struct Node* left;
	struct Node* right;
	int data;

	Node(int val){

		data=val;
		left=NULL;
		right=NULL;
	}
};


int main(){

	struct Node* root= new Node(2);
	root->left=new Node(3);
	root->right=new Node(5);

}

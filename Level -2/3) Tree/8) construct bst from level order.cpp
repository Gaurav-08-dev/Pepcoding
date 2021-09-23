/* TC-> O(N^2) */

Node* build(Node* root,int data)
{
    if(!root) 
    {
        root=new Node(data);
        return root;
    }
    
    if(data <= root->data)
    {
        root->left=build(root->left,data);
    }
    else
    {
        root->right=build(root->right,data);
    }
    return root;
}

Node* constructBst(int arr[], int n)
{
    if(n==0) return NULL;
    Node* root =NULL;
    for(int i=0;i<n;i++)
    {
        root=build(root,arr[i]);
    }
    return root;
}

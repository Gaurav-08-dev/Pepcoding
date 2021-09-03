void singlechildparentcount(TreeNode* root,int &count)
{
    if(!root or (root->left==NULL and root->right==NULL)) return;
    
    if(root->left==NULL or root->right==NULL)
    {
        count++;
    }
    
    singlechildparentcount(root->left,count);
    singlechildparentcount(root->right,count);
}


int countExactlyOneChild(TreeNode* node)
{
    int count=0;
    singlechildparentcount(node,count);
  return count;
}
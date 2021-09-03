void singlechildparent(TreeNode* root,vector<int> &ans)
{
    if(!root or (root->left==NULL and root->right==NULL)) return;
    
    if(root->left==NULL or root->right==NULL)
    {
        ans.push_back(root->val);
    }
    
    singlechildparent(root->left,ans);
    singlechildparent(root->right,ans);
}

vector<int> exactlyOneChild(TreeNode* root)
{
    vector<int> ans;
    
    singlechildparent(root,ans);
  return ans;
}

bool hasPathSum(TreeNode* root, int sum)
{
  if(!root) return false;
  
  sum=sum-root->val;
  
  if(sum==0 and !root->left and !root->right)
    return true;
    
    return hasPathSum(root->left,sum) or hasPathSum(root->right,sum);
}
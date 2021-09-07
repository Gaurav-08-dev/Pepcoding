
int solve(TreeNode* root,int &maxSum)
{
    if(!root) return 0;
    
    int ls=max(0,solve(root->left,maxSum));
    int rs=max(0,solve(root->right,maxSum));
    maxSum= max(maxSum,ls + rs + root->val);
    return root->val + max(ls,rs);
}
int maxPathSum(TreeNode* root) {
    int maxSum=INT_MIN;
    solve(root,maxSum);
    
    return maxSum;
}


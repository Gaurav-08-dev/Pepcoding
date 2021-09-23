void width(TreeNode* root,int count,int &lh, int &rh)
{
    if(!root) return;

    if(count<lh) lh=count;
    else if(count >rh) rh=count;

    width(root->left,count-1,lh,rh);
    width(root->right,count+1,lh,rh);

}

int width(TreeNode *root)
{
    if(!root) return 0;
    int lh=0,rh=0;

    width(root,0,lh,rh);

    return rh- lh + 1;
}

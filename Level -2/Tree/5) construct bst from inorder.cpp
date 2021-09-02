TreeNode* build(vector<int> &in, int start, int end)
{
    if(start>end)
    return nullptr;
    
    int mid=start + (end - start)/2;
    
    TreeNode* root=new TreeNode(in[mid]);
    
    root->left=build(in,start,mid-1);
    root->right=build(in,mid+1,end);
    
    return root;
}
TreeNode *constructFromInOrder(vector<int> &in)
{
    if(in.size()==0)
    return nullptr;
    
    return build(in,0,in.size()-1);
}

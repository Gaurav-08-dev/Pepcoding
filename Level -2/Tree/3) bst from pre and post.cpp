TreeNode *build(vector<int> &pre, vector<int> &post,int prestart,int preend,int poststart,int postend)
{
    if(prestart == preend)
        return new TreeNode(pre[prestart]);
        
    if(prestart > preend)
        return nullptr;
        
    TreeNode* root=new TreeNode(pre[prestart]);
    
    int element=pre[prestart+1];
    int index=poststart;
    
    while(element!=post[index])
    {
        index++;
    }
    
    int count=index - poststart +1;
    
    root->left=build(pre,post,prestart +1,prestart+count,poststart,index);
    root->right=build(pre,post,prestart+ count + 1,preend,index+1,preend-1);
    
    return root;
    
}
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    if(pre.size()==0)
        return nullptr;
    
    return build(pre,post,0,pre.size()-1,0,post.size()-1);
}
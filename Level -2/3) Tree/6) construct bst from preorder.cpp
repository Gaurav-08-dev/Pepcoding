



 TreeNode* build(vector<int>& preorder,int &index, int rr)
    {
        if(index==preorder.size() or preorder[index]>rr)
            return nullptr;

        
        int val=preorder[index++];
        // cout<<index;
        
        TreeNode* root=new TreeNode(val);
        
        root->left=build(preorder,index,val);
        root->right=build(preorder,index,rr);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return build(preorder,index,INT_MAX);
    }
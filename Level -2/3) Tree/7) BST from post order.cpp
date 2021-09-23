



 TreeNode* build(vector<int>& postorder,int &index, int lr,int rr)
    {
        if(index==postorder.size() or postorder[index]>rr or postorder[index]<lr)
            return nullptr;

        
        int val=postorder[index++];
        // cout<<index;
        
        TreeNode* root=new TreeNode(val);
        
        root->right=build(postorder,index,val,rr);
        root->left=build(postorder,index,lr,val);
        
        return root;
    }
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        int index=postorder.size()-1;
        return build(postorder,index,INT_MAX);
    }
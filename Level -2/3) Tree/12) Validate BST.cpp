
    
    TreeNode* prev=NULL;
    
    bool check(TreeNode* root)
    {   if(root==NULL) return true;
        
        if(!check(root->left,prev)) return false;
        
        if(prev!=NULL and prev->val >= root->val) return false;
        
        prev=root;
        
        if(!check(root->right,prev)) return false;
        
        return true;
    }
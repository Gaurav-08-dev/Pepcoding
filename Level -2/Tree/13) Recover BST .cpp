void inorder(TreeNode* root,TreeNode* &prev,vector<pair<TreeNode*, TreeNode*>> &vp)
    {
        if(!root) return;
        
        inorder(root->left,prev,vp);
        
        if(prev && prev->val > root->val) vp.push_back({prev,root});
        prev=root;
        
        inorder(root->right,prev,vp);
    }


    void recoverTree(TreeNode* root) {
        
    TreeNode* prev=NULL;
    vector<pair<TreeNode*, TreeNode*>> vp;
    
        
        inorder(root,prev,vp);
        
        if(vp.size()==1)
        {
            swap(vp[0].first->val,vp[0].second->val);
        }
        
        if(vp.size()==2)
        {
            swap(vp[0].first->val,vp[1].second->val);
        }
        
        
    }

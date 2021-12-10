TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root or root==p or root==q) return root;

        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;
        else{ return root;}
    }
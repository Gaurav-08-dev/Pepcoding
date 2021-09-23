TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q)
{   
        if(root==NULL or root->val==p or root->val==q) return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left== NULL) return right;
        else if(right==NULL) return left;
        else
            return root;
}
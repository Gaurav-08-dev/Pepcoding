/* O(N^2)*/

int height(TreeNode* root)
{
	if(!root) return -1;
	return max(height(root->left),height(root->right))+1;
}

int diameterOfBinaryTree(TreeNode* root) {
	if(!root) return 0;    

	int ld= diameterOfBinaryTree(root->left);
	int rd= diameterOfBinaryTree(root->right);

	int f=height(root->left) +height(root->right) +2;
    
    int dia=max(f,max(ld,rd));

	return dia;
}



    /* O(N) method*/

int height(TreeNode* root,int &diameter)
    {
        if(!root) return 0;    
        
        int ld= height(root->left,diameter);
        int rd= height(root->right,diameter);
        
        diameter= max(diameter,ld + rd);
        
        return 1 + max(ld ,rd);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
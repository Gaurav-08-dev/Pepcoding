/*** Brute-force methode ****/
	
	// 1) store the inorder traversal of tree and apply binary search 

// TC-> O(N)+ O(LOG(N))
// SC-> O(N)


/* Approach - 2 */

// while doing inorder search find the value > target;


/*** Efficient approach ****/


TreeNode* successor(TreeNode* root, TreeNode* target){
TreeNode* successor=NULL;
	while(root!=NULL){
		if(target->val >= root->val) root=root->right;
		else{ 

			successor=root;
			root=root->left;
		}
	}

	return successor;
}


TreeNode* predecessor(TreeNode* root, TreeNode* target){
TreeNode* predecessor=NULL;
	while(root!=NULL){
		if(target->val >= root->val){
			predecessor=root;
			root=root->right;}
		else{ 
			root=root->left;
		}
	}

	return predecessor;
}
TreeNode* ceil (TreeNode* root,int key){

	int ceil=-1;

	while(root!=NULL){
		if(root->val==key){ceil=key; return ceil;}
	
		if(root->val>key){
			ceil=root->val
			root=root->left;}

		else{
		root=root->right;}
	}

	return ceil;

}

TreeNode* floor (TreeNode* root,int key){

	int floor=-1;

	while(root!=NULL){
		if(root->val==key){floor=key; return floor;}
	
		if(root->val>key){
			root=root->left;}

		else{
			floor=root->val;
		root=root->right;}
	}

	return floor;

}

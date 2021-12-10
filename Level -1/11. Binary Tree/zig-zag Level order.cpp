vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    if(!root) return {};

    vector<vector<int>> ans;

    queue<TreeNode*> nodes;

    nodes.push(root);
    bool flag=false;
    while(!nodes.empty()){

    	int n=nodes.size();

    	vector<int> levels;
    	for(;n>0;n--){
    		TreeNode* curr=nodes.front(); nodes.pop();

    		if(curr->left) levels.push_back(curr->left);
    		if(curr->right) levels.push_back(curr->right);
    		levels.push_back(curr->val);
    	}

    	if(flag) reverse(levels.begin(),levels.end());
    	ans.push_back(levels);
    	flag=!flag;
    	
    }

    return ans;
}
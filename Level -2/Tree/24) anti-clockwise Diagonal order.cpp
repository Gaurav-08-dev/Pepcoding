/* Recursive */

void solve(TreeNode* root,int d,map<int,vector<int>> &m)
{
    if(!root) return;
    
    m[d].push_back(root->val);
    
    solve(root->left,d+1,m);
    solve(root->right,d,m);
}

vector<vector<int>> diagonalOrder(TreeNode *root)
{
	vector<vector<int>> ans;
	map<int,vector<int>> m;
	
	if(!root) return ans;
	
	solve(root,0,m);
	for(auto y: m)
	{
	    ans.push_back(y.second);
	}
	return ans;
}


/* Iterative */

vector<vector<int>> diagonalOrder(TreeNode *root)
{
	vector<vector<int>> ans;
	
	if(!root) return ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
		int factor_size=q.size();
		 vector<int> temp;
		while(factor_size--)
		{
		 TreeNode* factor=q.front(); q.pop();
		 	while(factor)
		    {
		        temp.push_back(factor->val);
		        if(factor->right)
			    q.push(factor->right);
		        
			    factor=factor->left;
		    }
		}
		ans.push_back(temp);	
	}
	return ans;
}
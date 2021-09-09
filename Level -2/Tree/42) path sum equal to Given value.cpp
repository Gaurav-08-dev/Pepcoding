
    int count=0,sum;
    unordered_map<int,int> seen;
    void dfs(TreeNode* root, int current_sum=0)
    {        
        // cout<<current_sum<<" ";
        current_sum+=root->val;
        count+=seen[current_sum-sum];
        seen[current_sum]++;
        
        if(root->left) dfs(root->left,current_sum);
        if(root->right) dfs(root->right,current_sum);
        
        seen[current_sum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        sum=targetSum;
        seen[0]=1;
        if(!root) return count;
        dfs(root);
        return count;
        
        
    }
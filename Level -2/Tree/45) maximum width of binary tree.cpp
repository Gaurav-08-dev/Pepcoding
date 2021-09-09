 int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        int max_width=0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            int min_index=q.front().second;
            
            int first,last;
            
            for(int i=0;i<size;i++)
            {
                int curr_index=q.front().second - min_index;
                TreeNode* node=q.front().first; q.pop();
                
                if(i==0) first=curr_index;
                if(i==size -1 ) last=curr_index;
                
                if(node->left) q.push({node->left,curr_index * 2 + 1});
                if(node->right) q.push({node->right,curr_index * 2 + 2});                
            }
            
            max_width=max(max_width, last - first + 1);
        }
        
        return max_width;
        
    }
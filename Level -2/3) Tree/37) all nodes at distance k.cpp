void markParents(TreeNode* root,TreeNode* target,unordered_map<TreeNode*, TreeNode*> &parent_map)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front(); q.pop();
            if(node->left) {
                parent_map[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                parent_map[node->right]=node;
                q.push(node->right);
            }
        }
        
    }
    
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParents(root,target,parent_map);
        
        unordered_map<TreeNode*, bool> visited;
        
        visited[target]=true;
        int curr_level=0;
        queue<TreeNode*> q;
        q.push(target);
        int distance=0;
        while(!q.empty())
        {
            int size=q.size();
            
            if(distance++==k) break;
            
            for(int i=0;i<size;i++)
            {
                TreeNode* current=q.front(); q.pop();
                if(current->left and !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left]=true;
                }
                 if(current->right and !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right]=true;
                }
                
                if(parent_map[current] and !visited[parent_map[current]])
                {
                    q.push(parent_map[current]);
                    visited[parent_map[current]]=true;
                }
                
            }
            
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* current=q.front(); q.pop();
            ans.push_back(current->val);
        }
        
        return ans;
        
    }
TreeNode* map_parents(TreeNode* root,int fireNode,map<TreeNode*,TreeNode*> &parents)
{
    TreeNode* res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        if(node->val==fireNode) res=node;
        q.pop();
        
        if(node->left) {
            q.push(node->left);
            parents[node->left]=node;
            
        }
        if(node->right)
        {
            q.push(node->right);
            parents[node->right]=node;   
        }
    }
    return res;
}
int findTime(TreeNode* root,TreeNode* start ,map<TreeNode*,TreeNode*> &parents)
{
    queue<TreeNode*> q;
    q.push(start);
    map<TreeNode*,int> visited;
    
    visited[start]=1;
    int tTime=0;
    
    while(!q.empty())
    {
        int isBurnt=0;
        int size=q.size();
        
        for(int i=0;i<size;i++)
        {
            
            TreeNode* node=q.front();q.pop();
            
            if(node->left and !visited[node->left])
            {
                isBurnt=1;
                visited[node->left]=1;
                q.push(node->left);
            }
            
            if(node->right and !visited[node->right])
            {
                isBurnt=1;
                visited[node->right]=1;
                q.push(node->right);
            }
            
            if(parents[node] and !visited[parents[node]])
            {
                isBurnt=1;
                visited[parents[node]]=1;
                q.push(parents[node]);
            }
        }
        if(isBurnt) tTime++;
    }
    
    return tTime;
}
int burningTree(TreeNode* root, int fireNode)
{
    map<TreeNode*,TreeNode*> parents;
    TreeNode* start=map_parents(root,fireNode,parents);
    
    int totalTime=findTime(root,start ,parents);
    return totalTime;
    
}

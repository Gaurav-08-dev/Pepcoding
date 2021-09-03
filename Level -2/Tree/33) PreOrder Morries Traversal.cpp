
TreeNode* getrightmostnode(TreeNode* temp,TreeNode* curr)
{
    while(temp->right!=NULL and temp->right!=curr)
    {
        temp=temp->right;
    }
    
    return temp;
}
vector<int> morrisPreTraversal(TreeNode* root) {
    
vector<int> ans;

TreeNode* curr=root;
    
while(curr!=NULL)
{
    TreeNode* leftnode=curr->left;
    if(leftnode != NULL)
    {
        TreeNode* rightmostnode=getrightmostnode(leftnode,curr);
        if(rightmostnode->right!=curr)
        {
            ans.push_back(curr->val);
            // create a thread and move towards left tree
            rightmostnode->right=curr; //thread creation
            curr=curr->left;
        }
        else
        {
            
            // break thread
            rightmostnode->right=NULL;
            
            // move towards right
            curr=curr->right;
        }
    }
    else
    {
        // print value
        ans.push_back(curr->val);
        
        // move towards right
        curr=curr->right;
    }
}

return ans;

}

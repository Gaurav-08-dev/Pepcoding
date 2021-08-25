class Solution {
public:
    
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd)
    {
        if(preStart > preEnd) return nullptr;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        int index=inStart;
        
        while(inorder[index]!=preorder[preStart])
        {
            index++;
        }
        
        int elementCount=index - inStart;
        
        root->left=construct(preorder,inorder,preStart+1,preStart + elementCount,inStart,index-1);
        
        root->right=construct(preorder,inorder,preStart+elementCount+1,preEnd,index+1,inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size()==0)
            return nullptr;
        
        return construct(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
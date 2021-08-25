class Solution {
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder,int instart,int inend,int poststart,int postend)
{
    if(poststart > postend) return nullptr;
    TreeNode* node=new TreeNode(postorder[postend]);
    int index=instart;
    
    while(postorder[postend]!=inorder[index]){
        index++;
    }
    
    int element_count=index-instart;
    
    node->left=build(inorder,postorder,instart,index-1,poststart,poststart+element_count-1);
    
    node->right=build(inorder,postorder,index+1,inend,poststart+element_count,postend-1);
    
    return node;

}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.size()==0) return nullptr;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
int countcamera(TreeNode* root,int &camera)
{
    
    if(!root) return 1;
    int lstate=countcamera(root->left,camera);
    int rstate=countcamera(root->right,camera);
    
    if(lstate==1 and rstate==1) return 2;
    
    else if(lstate==2 or rstate==2){ camera++; return 0;}
    
    else return 1;
}

int MinCamerasInBT(TreeNode *root)
{
    int camera=0;
    
    if(countcamera(root,camera)==2) camera++;
    return camera;
}
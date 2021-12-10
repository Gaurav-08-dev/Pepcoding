/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */







// USING 1 Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> post;
        
        stack<TreeNode*> st;
        
        TreeNode* curr=root;
        
        while(!st.empty() or curr!=NULL){
            
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp;
                temp=st.top()->right; 
                
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    post.push_back(temp->val);
                    while(!st.empty() and temp==st.top()->right){
                        temp=st.top(); st.pop();
                        post.push_back(temp->val);
                    }
                }else{
                    curr=temp;
                }
            }
        }
        
        return post;
    }
};
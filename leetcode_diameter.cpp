class Solution {
public:
    int height(TreeNode*root){
        if(!root){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans1=diameterOfBinaryTree(root->left);
        int ans2=diameterOfBinaryTree(root->right);
        int ans3=height(root->left)+height(root->right);
        return max(ans1,max(ans2,ans3))+1;
    }
};
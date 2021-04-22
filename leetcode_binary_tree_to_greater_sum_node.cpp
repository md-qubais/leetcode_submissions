class Solution{
public:
    int num=0;
    TreeNode* convertBST(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        root->right=convertBST(root->right);
        root->val+=num;
        num=root->val;
        root->left=convertBST(root->left);
        return root;
    }
};
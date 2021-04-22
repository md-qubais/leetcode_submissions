class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root){
    	if(!root){
    		return 0;
    	}
    	if(root->left and !root->left->left and !root->left->right){
    		return root->left->val;
    	}
    	int op1=sumOfLeftLeaves(root->left);
    	int op2=sumOfLeftLeaves(root->right);
    	return op1+op2;
    }
};
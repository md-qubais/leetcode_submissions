class Solution {
public:
	int height(TreeNode*root){
		if(root==NULL){
			return 0;
		}
		return 1+height(root->left)+height(root->right);
	}
    int minDepth(TreeNode* root){
    	if(root->left==NULL){
    		return height(root->right)+1;
    	}
    	if(root->right==NULL){
    		return height(root->left)+1;
    	}
    	return min(height(root->left),height(root->right))+1;
    }
};
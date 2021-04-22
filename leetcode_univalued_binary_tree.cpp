class Solution {
public:
	int val;
	int is_it(TreeNode*root){
		if(root==NULL){
			return val;
		}
		int left=is_it(root->left);
		if(left!=root->val or left==-1){
			return -1;
		}
		int right=is_it(root->right);
		if(right!=root->val or right==-1){
			return -1;
		}
		return root->val;
	}
    bool isUnivalTree(TreeNode* root){
    	val=root->val;
    	if(is_it(root)==-1) return false;
    	return true;
    }
};
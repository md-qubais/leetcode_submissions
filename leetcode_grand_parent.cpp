class Solution {
public:
	int ans=0;
	void sum(TreeNode*root){
		if(!root){
			ans+=0;
			return;
		}
		if(root->left and root->left->left and (root->val)%2==0){
			ans+=root->left->left->val;
		}
		if(root->left and root->left->right and (root->val)%2==0){
			ans+=root->left->right->val;
		}
		if(root->right and root->right->right and (root->val)%2==0){
			ans+=root->right->right->val;
		}
		if(root->right and root->right->left and (root->val)%2==0){
			ans+=root->right->left->val;
		}
		sum(root->left);
		sum(root->right);
	}
    int sumEvenGrandparent(TreeNode* root){
    	sum(root);
    	return ans;
    }
};
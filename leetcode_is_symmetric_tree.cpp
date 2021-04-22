
class Solution {
public:
	bool compare(TreeNode*left,TreeNode*right){
		if(left==NULL and right==NULL){
			return true;
		}
		if(left and right==NULL){
			return false;
		}
		if(right and left==NULL){
			return false;
		}
		if(left->val!=right->val){
			return false;
		}
		bool ans1=compare(left->left,right->right);
		if(!ans1){
			return false;
		}
		bool ans2=compare(left->right,right->left);
		if(!ans2){
			return false;
		}
		return true;
	}
    bool isSymmetric(TreeNode* root) {
        return compare(root,root);
    }
};
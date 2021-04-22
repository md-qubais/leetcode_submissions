class Solution {
public:
    bool check(TreeNode*root,long Min,long Max){
	if(root==NULL){
		return true;
	}
	bool ans1=check(root->left,Min,root->val);
	if(ans1==false){
		return false;
	}
	bool ans2=check(root->right,root->val,Max);
	if(ans2==false){
		return false;
	}
	if(root->val>Min and root->val<Max){
		return true;
	}
	return false;
}

    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};
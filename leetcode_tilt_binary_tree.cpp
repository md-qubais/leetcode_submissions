class Pair{
public:
	int tot;
	Pair(){
		tot=0;
	}
};
class Solution {
public:
	int sum(TreeNode*root){
		if(root==NULL){
			return 0;
		}
		return root->val+sum(root->left)+sum(root->right);
	}
	Pair Tilt(TreeNode*root){
		Pair p;
		if(root==NULL){
			return p;
		}
		Pair left=Tilt(root->left);
		Pair right=Tilt(root->right);
		p.tot=left.tot+right.tot+root->val;
		root->val=abs(left.tot-right.tot);
		return p;
	}
    int findTilt(TreeNode* root){
    	Tilt(root);
    	return sum(root);
    }
};
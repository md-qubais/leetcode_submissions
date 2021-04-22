class Pair{
public:
	long long max;
	long long min;
	bool isbst;
	Pair(){
		max=LONG_MIN;
		min=LONG_MAX;
		isbst=true;
	}
};
class Solution {
public:
	Pair check(TreeNode*root){
		Pair p;
		if(!root) return p;
		Pair left=check(root->left);
		Pair right=check(root->right);
		if(!left.isbst or !right.isbst){
			p.isbst=false;
			return p;
		}
		if(root->val>left.max and root->val<right.min){
			if(root->val>right.max){
				p.max=root->val;
			}else{
				p.max=right.max;
			}
			if(root->val<left.min){
				p.min=root->val;
			}else{
				p.min=left.min;
			}
			p.isbst=true;
			return p;
		}
		p.isbst=false;
		return p;
	}
    bool isValidBST(TreeNode* root){
    	if(!root->left and !root->right){
    		return true;
    	}
    	Pair ans=check(root);
    	return ans.isbst;
    }
};
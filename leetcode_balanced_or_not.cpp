class Pair{
public:
	bool ans;
	int height;
};

Pair is_balanced_fast(TreeNode*root){
	Pair p;
	if(root==NULL){
		p.height=0;
		p.ans=true;
		return p; 
	}
	Pair left=is_balanced_fast(root->left);
	Pair right=is_balanced_fast(root->right);
	p.height=1+max(left.height,right.height);
	if(left.ans and right.ans){
		int num=left.height-right.height;
		p.ans=num==0 or num==-1 or num==1;
		return p;
	}
	p.ans=false;
	return p;
}

class Solution {
public:
    bool isBalanced(TreeNode* root){
    	Pair p;
    	p=is_balanced_fast(root);
    	return p.ans;
    }
};
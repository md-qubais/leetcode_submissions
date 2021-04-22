class Pair{
public:
long long max;
long long min;
int sum;
bool isbst;
Pair(){
	sum=0;
	max=LONG_MIN;
	min=LONG_MAX;
	isbst=true;

}
};

class Solution {
public:
	int ans=0;
    Pair check(TreeNode*root){
	Pair p;
	if(!root) return p;
	Pair left=check(root->left);
	Pair right=check(root->right);
	if(!left.isbst or !right.isbst){
		p=right.sum>left.sum?right:left;
		p.isbst=false;
		return p;
	}
	if(root->val>left.max and root->val<right.min){
		p.sum=left.sum+right.sum+root->val;
		ans=max(ans,p.sum);
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
    p=right.sum>left.sum?right:left;
    p.isbst=false;
    return p;
}
int maxSumBST(TreeNode* root){
	if(!root) return 0;
	Pair p=check(root);
	return ans;
}
};
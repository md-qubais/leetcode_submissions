class Pair{
public:
	int height;
	int diameter;
	Pair(){
		height=diameter=0;
	}
};
class Solution {
public:
	Pair diameter(TreeNode*root){
		Pair p;
		if(!root){
			return p;
		}
		Pair left=diameter(root->left);
		Pair right=diameter(root->right);
		p.height=1+max(left.height,right.height);
		int op1=left.diameter;
		int op2=right.diameter;
		int op3=left.height+ right.height;
		p.diameter=max(op1,max(op2,op3));
		return p;
	}
    int diameterOfBinaryTree(TreeNode* root){
    	Pair p=diameter(root);
    	return p.diameter;
    }
};


class Solution {
public:
	TreeNode* Insert(TreeNode*root,int val,int k,int level){
		if(root==NULL){
			return NULL;
		}
		if(k==level){
			//if it has left child
			if(root->left){
				TreeNode*n=new TreeNode(val);
				n->left=root->left;
				root->left=n;
			}else{
				TreeNode*n=new TreeNode(val);
				root->left=n;
			}
			//if it has right child
			if(root->right){
				TreeNode*n=new TreeNode(val);
				n->right=root->right;
				root->right=n;
			}else{
				TreeNode*n=new TreeNode(val);
				root->right=n;
			}
			return root;
		}
		root->left=Insert(root->left,val,k,level+1);
		root->right=Insert(root->right,val,k,level+1);
		return root;
	}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
        	TreeNode*n=new TreeNode(val);
        	n->left=root;
        	root=n;
        	return root;
        }
        root=Insert(root,val,depth-1,1);
        return root;
    }
};
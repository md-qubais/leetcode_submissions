class Solution {
public:
	TreeNode* construct(vector<int>&pre,vector<int>&in,int s,int e,int&i){
		if(s>e){
			return NULL;
		}
		TreeNode*root=new TreeNode(pre[i++]);
		int mid;
		for(int j=s;j<=e;j++){
			if(root->val==in[j]){
				mid=j;
				break;
			}
		}
		root->left=construct(pre,in,s,mid-1,i);
		root->right=construct(pre,in,mid+1,e,i);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int i=0;
    	return construct(preorder,inorder,0,preorder.size()-1,i);
    }
};
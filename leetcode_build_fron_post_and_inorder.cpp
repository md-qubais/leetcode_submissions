class Solution {
public:
	TreeNode* construct(vector<int>&post,vector<int>&in,int s,int e,int &i){
		if(s>e){
			return NULL;
		}
		TreeNode*root=new TreeNode(post[i--]);
		int mid;
		for(int j=s;j<=e;j++){
			if(in[j]==root->val){
				mid=j;
				break;
			}
		}
		root->right=construct(post,in,mid+1,e,i);
		root->left=construct(post,in,s,mid-1,i);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int i=inorder.size()-1;
        return construct(postorder,inorder,0,inorder.size()-1,i);
    }
};
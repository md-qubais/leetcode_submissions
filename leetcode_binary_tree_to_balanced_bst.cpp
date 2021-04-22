class Solution{
public:
	void convert(TreeNode*root,vector<int>&arr){
		if(!root) return;
		convert(root->left,arr);
		arr.push_back(root->val);
		convert(root->right,arr);
	}
	TreeNode* create(vector<int>&arr,int s,int e){
		if(s>e){
			return NULL;
		}
		int mid=(s+e)/2;
		TreeNode *root=new TreeNode(arr[mid]);
		root->left=create(arr,s,mid-1);
		root->right=create(arr,mid+1,e);
		return root;
	}
    TreeNode* balanceBST(TreeNode* root){
    	if(!root) return NULL;
    	vector<int> arr;
    	convert(root,arr);
    	root=NULL;
    	return create(arr,0,arr.size()-1);
    }
};
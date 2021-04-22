class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>&arr,int s,int e){
		if(s>e){
			return NULL;
		}
		int mid=(s+e)/2;
		TreeNode*root=new TreeNode(arr[mid]);
		root->left=sortedArrayToBST(arr,s,mid-1);
		root->right=sortedArrayToBST(arr,mid+1,e);
		return root;
	}
    TreeNode* sortedArrayToBST(vector<int>&arr){
    	return sortedArrayToBST(arr,0,arr.size()-1);
    }
};
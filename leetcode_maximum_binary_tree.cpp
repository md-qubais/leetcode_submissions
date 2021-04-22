class Solution {
public:
	TreeNode* create(vector<int>&nums,int s,int e){
		if(s>e){
			return NULL;
		}
		int Max_index=-1;
		int curr=INT_MIN;
		for(int i=s;i<=e;i++){
			if(curr<nums[i]){
				curr=nums[i];
				Max_index=i;
			}
		}
		if(Max_index==-1){
			return NULL;
		}
		TreeNode*root=new TreeNode(nums[Max_index]);
		root->left=create(nums,s,Max_index-1);
		root->right=create(nums,Max_index+1,e);
		return root;
	}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    	return create(nums,0,nums.size()-1);
    }
};
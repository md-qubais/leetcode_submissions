class Solution {
public:
	vector<int> tree1;
	vector<int> tree2;
	void preorder(TreeNode*root,int num){
		if(root==NULL){
			return;
		}
		if(num==1){
			tree1.push_back(root->val);
		}else{
			tree2.push_back(root->val);
		}
		preorder(root->left,num);
		preorder(root->right,num);
	}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    	preorder(root1,1);
    	preorder(root2,2);
    	vector<int> ans;
    	for(auto it:tree1){
    		ans.push_back(it);
    	}
    	for(auto it:tree2){
    		ans.push_back(it);
    	}
    	sort(ans.begin(),ans.end());
    	return ans;
    }
};



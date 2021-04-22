class Solution {
public:
	set<int> s;
	void sum_help(TreeNode*root,int num){
		if(root==NULL){
			s.insert(num);
			return;
		}
		sum_help(root->left,(root->val)+num*10);
		sum_help(root->right,(root->val)+num*10);

	}
    int sumNumbers(TreeNode* root){
    	sum_help(root,0);
    	int ans=0;
    	for(auto it:s){
            cout<<it<<endl;
    		ans+=it;
    	}
    	return ans;
    }
};
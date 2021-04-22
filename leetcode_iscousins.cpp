class Solution{
public:
	vector<int> node_to_root(TreeNode*root,int num){
		vector<int> ans;
		if(!root){
			return ans;
		}
		if(root->val==num){
			ans.push_back(root->val);
			return ans;
		}
		vector<int> left=node_to_root(root->left,num);
		vector<int> right=node_to_root(root->right,num);
		if(left.size()>0 and right.size()==0){
			for(auto it:left){
				ans.push_back(it);
			}
			ans.push_back(root->val);
			return ans;
		}
		if(right.size()>0 and left.size()==0){
			for(auto it:right){
				ans.push_back(it);
			}
			ans.push_back(root->val);
			return ans;	
		}
		return ans;
	}
    bool isCousins(TreeNode* root, int x, int y){
    	vector<int> left=node_to_root(root,x);
    	vector<int> right=node_to_root(root,y);
    	for(auto it:left){
    		cout<<it<<" ";
    	}
    	cout<<endl;
    	for(auto it:right){
    		cout<<it<<" ";
    	}
    	cout<<endl;
    	if(left.size()==right.size()){
    		return true?left[1]!=right[1]:false;
    	}
    	return false;
    }
};
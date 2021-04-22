class Solution{
public:
	vector<TreeNode*> get_path(TreeNode*root,TreeNode*target){
		vector<TreeNode*> res;
		if(!root){
			return res;
		}
		if(root==target){
			res.push_back(root);
			return res;
		}
		vector<TreeNode*> left=get_path(root->left,target);
		if(left.size()>0){
			for(auto it:left){
				res.push_back(it);
			}
			res.push_back(root);
			return res;
		}
		vector<TreeNode*> right=get_path(root->right,target);
		if(right.size()>0){
			for(auto it:right){
				res.push_back(it);
			}
			res.push_back(root);
			return res;
		}
		return res;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    	vector<TreeNode*> op1=get_path(root,p);
    	vector<TreeNode*> op2=get_path(root,q);
    	int i=op1.size()-1;
    	int j=op2.size()-1;
    	
    	while(i>=0 and j>=0 and op1[i]==op2[j]){
    		i--;
    		j--;
    	}
    	return op1[++i];
    }
};
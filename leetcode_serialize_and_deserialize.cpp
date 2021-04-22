class Codec {
public:
	TreeNode* build(TreeNode*root,int val){
		if(root==NULL){
			return new TreeNode(val);
		}
		if(root->val>val){
			root->left=build(root->left,val);
			return root;
		}
		root->right=build(root->right,val);
		return root;

	}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root){
    	if(!root){
            return "";
        }
        string ans="";
    	queue<TreeNode*> q;
    	q.push(root);
    	while(!q.empty()){
    		TreeNode*temp=q.front();
    		q.pop();
    		ans+=to_string(temp->val)+" ";
    		if(temp->left) q.push(temp->left);
    		if(temp->right) q.push(temp->right);
    	}
    	return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data){
    	vector<string> arr;
    	vector<int> nums;
    	string temp="";
    	for(auto it:data){
    		temp+=it;
    		if(it==' '){
    			if(temp.size()>0){
    				arr.push_back(temp);
    				temp="";
    			}
    		}
    	}
    	for(auto it:arr){
    		stringstream stream(it);
    		int x = 0;
    		stream>> x;
    		nums.push_back(x);
    	}
    	TreeNode*root=NULL;
    	for(auto it:nums){
    		root=build(root,it);
    	}
    	return root;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
    	vector<vector<int>> ans;
    	if(!root){
    		return ans;
    	}
    	deque<TreeNode*> q1,q2;
    	q1.push_back(NULL);
    	q2.push_back(NULL);

    	q1.push_back(root);
    	q2.push_back(root);

    	q1.push_back(NULL);
    	q2.push_back(NULL);
    	while(!q1.empty()){
    		TreeNode*temp=q1.front();
    		q1.pop_front();
    		if(temp==NULL){
    			if(q1.size()>0 and q1.front()!=NULL){
    				q1.push_back(NULL);
    				q2.push_back(NULL);
    			}
    		}else{
    			if(temp->right){
    				q1.push_back(temp->right);
    				q2.push_back(temp->right);
    			}
    			if(temp->left){
    				q1.push_back(temp->left);
    				q2.push_back(temp->left);
    			}
    		}
    	}
        vector<int> temp;
    	while(!q2.empty()){
    		if(!q2.back()){
    			q2.pop_back();
                if(temp.size()>0) ans.push_back(temp);
                temp.erase(temp.begin(),temp.end());
    			continue;
    		}
            temp.push_back(q2.back()->val);
    		q2.pop_back();
    	}
    	return ans;
    }
};
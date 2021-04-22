class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q;
        vector<int> ans;
        if(root==NULL){
        	return ans;
        }
        q.push_back(root);
        q.push_back(NULL);
        while(!q.empty()){
        	TreeNode*temp=q.front();
        	q.pop_front();
        	if(temp==NULL){
        		if(q.size()>0){
        			q.push_back(NULL);
        		}
        	}else{
        		if(q.front()==NULL){
        			ans.push_back(temp->val);
        		}
        		//insert its childrens
        		if(temp->left) q.push_back(temp->left);
        		if(temp->right) q.push_back(temp->right);
        	}
        }
        return ans;
    }
};
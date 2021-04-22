
class Solution {
public:
	vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node* root){
    	if(root==NULL){
            return ans;
        }
        deque<Node*> q;
    	vector<int> temp;
    	q.push_back(root);
    	q.push_back(NULL);
    	while(!q.empty()){
    		Node*n=q.front();
    		q.pop_front();
    		if(n==NULL){
    			if(temp.size()>0) ans.push_back(temp);
    			temp.erase(temp.begin(),temp.end());
    			q.push_back(NULL);
    		}else{
    			temp.push_back(n->val);
    			for(auto it:n->children){
    				q.push_back(it);
    			}
    		}
    		if(q.size()==1 and q.front()==NULL){
    			if(temp.size()>0) ans.push_back(temp);
    			return ans;
    		}
    	}
    	return ans;
    }
};
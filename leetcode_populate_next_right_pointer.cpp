class Solution {
public:
    Node* connect(Node* root){
    	//now by using bfs we can do this question easily
    	deque<Node*> q;
        if(root==NULL){
            return NULL;
        }
    	q.push_back(root);
    	q.push_back(NULL);
    	while(!q.empty()){
    		Node*temp=q.front();
    		q.pop_front();
    		if(temp==NULL){
    			if(q.size()>0){
    				q.push_back(NULL);
    			} 
    		}else{
    			temp->next=q.front();
    			if(temp->left) q.push_back(temp->left);
    			if(temp->right) q.push_back(temp->right);
    		}
    	}
    	return root;
    }
};
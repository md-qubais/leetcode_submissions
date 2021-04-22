class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key){
    	if(root==NULL){
    		return NULL;
    	}
    	if(root->val==key){
    		if(root->left==NULL and root->right==NULL){
    			delete root;
    			return NULL;
    		}
    		if(root->left==NULL and root->right!=NULL){
    			TreeNode*temp=root->right;
    			delete root;
    			return temp;
    		}
    		if(root->left!=NULL and root->right==NULL){
    			TreeNode*temp=root->left;
    			delete root;
    			return temp;
    		}
    		TreeNode*temp=root->right;
    		while(temp->left){
    			temp=temp->left;
    		}
    		swap(root->val,temp->val);
    		root->right=deleteNode(root->right,temp->val);
            return root;
    	}
    	if(root->val>key){
    		root->left=deleteNode(root->left,key);
    		return root;
    	}
    	root->right=deleteNode(root->right,key);
    	return root;
    }
};
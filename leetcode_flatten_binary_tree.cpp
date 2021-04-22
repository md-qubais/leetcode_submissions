class Linkedlist{
public:
	TreeNode*head;
	TreeNode*tail;
	Linkedlist(){
		head=tail=NULL;
	}
};
     Linkedlist flatten_it(TreeNode* root){
    	Linkedlist l;
    	if(root==NULL){
    		return l;
    	}
    	if(root->right==NULL and root->left==NULL){
    		l.head=root;
    		l.tail=root;
    		return l;
    	}
    	if(root->left==NULL and root->right!=NULL){
    		l=flatten_it(root->right);
    		root->right=l.head;
    		l.head=root;
    		return l;
    	}
    	if(root->right==NULL and root->left!=NULL){
    		l=flatten_it(root->left);
    		l.tail->right=root;
    		l.tail=root;
    		return l;
    	}
    	Linkedlist l1=flatten_it(root->left);
    	Linkedlist l2=flatten_it(root->right);
    	l1.tail->right=l2.head;
    	root->right=l1.head;
    	l.head=root;
    	l.tail=l2.tail;
    	return l;
    }



class Solution {
public:
    void flatten(TreeNode* root){
        if(!root){
            return ;
        }
    Linkedlist l=flatten_it(root);
    root=l.head;
    while(l.head->right){
    	cout<<l.head->val<<endl;
    	l.head->left=NULL;
    	l.head=l.head->right;
    }      
    }
};


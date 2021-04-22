class Solution {
public:
	TreeNode* get_next_left(stack<pair<TreeNode*,int>>&s){
	while(!s.empty()){
		pair<TreeNode*,int> temp=s.top();
		s.pop();
		if(temp.second==0){
			temp.second++;
			s.push(make_pair(temp.first,temp.second));
			if(temp.first->left) s.push(make_pair(temp.first->left,0));
		}else if(temp.second==1){
			if(temp.first->right) s.push(make_pair(temp.first->right,0));
			return temp.first;
		}
	}
	return NULL;
}

TreeNode* get_next_right(stack<pair<TreeNode*,int>>&s){
	while(!s.empty()){
		pair<TreeNode*,int> temp;
		temp=s.top();
		s.pop();
		if(temp.second==0){
			temp.second++;
			s.push(temp);
			if(temp.first->right) s.push(make_pair(temp.first->right,0));
		}else if(temp.second==1){
			if(temp.first->left) s.push(make_pair(temp.first->left,0));
			return temp.first;
		}
	}
	return NULL;
}
bool findTarget(TreeNode*root,int k){
	stack<pair<TreeNode*,int>> left;
	stack<pair<TreeNode*,int>> right;
	left.push(make_pair(root,0));
	right.push(make_pair(root,0));
	TreeNode*l=get_next_left(left);
	TreeNode*r=get_next_right(right);
	while(r and l and l->val<r->val){
		if(l->val+r->val==k){
			return true;
		}
		else if(l->val+r->val<k){
			l=get_next_left(left);
		}else{
			r=get_next_right(right);
		}
	}
	return false;
}
};
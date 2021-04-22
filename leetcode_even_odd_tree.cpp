
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
    deque<pair<TreeNode*,int>> q;
	q.push_back(make_pair(root,0));
	int prev=0;
	vector<int> arr;
	while(!q.empty()){
		TreeNode*temp=q.front().first;
		int curr=q.front().second;
		q.pop_front();
		if(temp->left)
			q.push_back(make_pair(temp->left,curr+1));
		if(temp->right){
			q.push_back(make_pair(temp->right,curr+1));
		}
		if(prev==curr){
			arr.push_back(temp->val);
		}else{
			if(prev%2==0){
				//here we need all odd in sorted
				if(arr.size()==1){
					if(arr[0]%2==0){
						return false;
					}
				}
				for(int i=0;i<arr.size()-1;i++){
					if(arr[i]>=arr[i+1] or arr[i]%2==0){
						return false;
					}
				}
				if(arr[arr.size()-1]%2==0){
					return false;
				}
				arr.erase(arr.begin(),arr.end());
			}else{
				//here we need all even sorted
				for(int i=0;i<arr.size()-1;i++){
					if(arr[i]<=arr[i+1] or arr[i]%2!=0){
						return false;
					}
				}
				if(arr[arr.size()-1]%2!=0){
					return false;
				}
				arr.erase(arr.begin(),arr.end());
			}
			arr.push_back(temp->val);
			prev++;
		}
	}
	if(prev%2==0){
				//here we need all odd in sorted
				if(arr.size()==1){
					if(arr[0]%2==0){
						return false;
					}
				}
				for(int i=0;i<arr.size()-1;i++){
					if(arr[i]>=arr[i+1] or arr[i]%2==0){
						return false;
					}
				}
				if(arr[arr.size()-1]%2==0){
					return false;
				}
				arr.erase(arr.begin(),arr.end());
			}else{
				//here we need all even sorted
				for(int i=0;i<arr.size()-1;i++){
					if(arr[i]<=arr[i+1] or arr[i]%2!=0){
						return false;
					}
				}
				if(arr[arr.size()-1]%2!=0){
					return false;
				}
				arr.erase(arr.begin(),arr.end());
			}
	return true;
  }
};
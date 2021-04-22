class Solution {
public:
	TreeNode* create(vector<pair<int,int>>&arr,int &i,int level){
		if(i>=arr.size()){
			return NULL;
		}
		if(arr[i].first<level){
			return NULL;
		}
		TreeNode*root=NULL;
		if(arr[i].first==level){
			 root=new TreeNode(arr[i++].second);
		}
		root->left=create(arr,i,level+1);
		root->right=create(arr,i,level+1);
		return root;
	}
    TreeNode* recoverFromPreorder(string s){
    	//first parse the string and convert it into
    	//something meaning full like array of pair
    	//pair.first=level
    	//pair.second=value
    	if(s.length()==0){
    		return NULL;
    	}
    	vector<pair<int,int>> arr;
    	int i=0;
    	string temp="";
    	while(i<s.length() and s[i]!='-'){
    		temp+=s[i++];
    	}
    	stringstream str(temp);
    	int num;
    	str>>num;//insertion operator
    	int level=0;
    	arr.push_back(make_pair(level,num));
    	int count=0;
    	for(;i<s.length();i++){
    		if(s[i]=='-'){
    			count++;
    		}else{
    			level=count;
    			count=0;
    			//now find number from that string
    			string temp="";
    			while(i<s.length() and s[i]!='-'){
    				temp+=s[i++];
    			}
    			stringstream str(temp);
    			int num;
    			str>>num;
    			arr.push_back(make_pair(level,num));
    			i--;
    			continue;
    		}
    	}  	
    	i=0;
    	return create(arr,i,0);
    }
};